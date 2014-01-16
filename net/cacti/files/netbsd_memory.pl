#!/usr/bin/perl
#
#	$NetBSD: netbsd_memory.pl,v 1.2 2014/01/16 21:10:00 tron Exp $
#
# Copyright (c) 2014 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Matthias Scheler.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

use warnings;
use strict;

use POSIX;

# Use vmstat(1) to get memory usage information. "vmstat -s" produces
# output lines like these:
#
#  2034763 pages managed
#    28953 pages free
#
# This function creates a hash using the description as a key to the value.

sub get_vm_stats()
{
	my %vm_stats;
	
	my $vmstat_fh;
	if (!open($vmstat_fh, '-|', '/usr/bin/vmstat -s')) {
		die('Cannot start vmstat.');
	}
	
	while (my $line = <$vmstat_fh>) {
		$line =~ s/^\s+//;
		$line =~ s/\s+$//;
		my @words = split(/\s+/, $line, 2);
		if (scalar(@words) < 2) {
			next;
		}
		my ($value, $descr) = @words;
	
		$vm_stats{$descr} = $value;
	}
	
	close($vmstat_fh);
	return %vm_stats;
}

if (scalar(@ARGV) < 1) {
	die('Please provide a field name');
}

my $page_size = POSIX::sysconf(&POSIX::_SC_PAGESIZE);
my %vm_stats = get_vm_stats();

# Calculate metrics using the stats reported by vmstat(1).
# Cacti only uses "MemFree" and "SwapFree" at the moment.
my $value = 0;
if ($ARGV[0] =~ 'MemTotal') {
	$value = $vm_stats{'pages managed'};
} elsif ($ARGV[0] =~ 'MemFree') {
	$value = $vm_stats{'pages free'};
} elsif ($ARGV[0] =~ 'Buffers') {
	$value = $vm_stats{'cached file pages'};
} elsif ($ARGV[0] =~ 'Cached') {
	$value = $vm_stats{'anonymous pages'} +
                 $vm_stats{'cached file pages'} +
                 $vm_stats{'cached executable pages'};
} elsif ($ARGV[0] =~ 'SwapTotal') {
	$value = $vm_stats{'swap pages'};
} elsif ($ARGV[0] =~ 'SwapFree') {
	$value = $vm_stats{'swap pages'} -
                 $vm_stats{'swap pages in use'};
}

print $value * ($page_size / 1024);
exit(0);
