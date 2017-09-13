#!/usr/bin/perl
#
# Copyright (c) 2016 Sebastien Marie <semarie@online.fr>
#
# Permission to use, copy, modify, and distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#

use strict;
use warnings;

use Digest::SHA qw(sha256_hex);
use File::Find;
use Getopt::Std;
use JSON::PP;
#use OpenBSD::Pledge;

# early pledge
#pledge('rpath wpath cpath') || err(1, "pledge: $!");

# print usage and exit
sub usage
{
	print "usage: $0 archive directory\n";
	exit 1
}

# print error and exit
sub err
{
	my ($exitcode, @rest) = @_;

	print STDERR "$0: error: @rest\n";

	exit $exitcode;
}

# read file, and generate hex of SHA256
sub sha256_file_hex
{
	my ($filename) = @_;

	my $sha = Digest::SHA->new("SHA256");
	$sha->addfile($filename);
	return $sha->hexdigest;
}

# create an empty file
sub create_empty
{
	my ($filename) = @_;
	open(my $fh, ">", $filename) || return 0;
	close($fh);
	return 1;
}

# generate checksum
sub generate_checksum_files
{
	my %files;

	find({ wanted =>
	    sub {
	        # remove ./ at begining
		s|^\./||;
		# skip .cargo* files (and prune)
		if (m|^.cargo|o) {
			$File::Find::prune = 1;
			return;
		}
		# skip any no file
		return if ! -f;
		return if m|/\.gitattributes$|o;

	        $files{$_} = sha256_file_hex($_);
	    }, follow => 0, no_chdir => 1, }, '.');

	return \%files;
}

my %options = ();

getopts("h", \%options) || usage;
usage if (defined $options{h} || scalar(@ARGV) != 2);

my $archive = $ARGV[0];
my $directory = $ARGV[1];

# check arguments
err(1, "archive '$archive' doesn't exist") if ! -f $archive;
err(1, "'$directory' isn't a directory") if ! -d $directory;

# move to directory
chdir($directory) || err(1, "chdir: '$directory'");
	
# place cargo.ok file inside the directory
create_empty(".cargo.ok")
	|| err(1, "create_empty: '$directory/.cargo.ok': $!");

# open checksum file for writing
open(my $fchecksum, ">", ".cargo-checksum.json")
	|| err(1, "open: '$directory/.cargo-checksum.json': $!");

# pledge filesystem readonly
#pledge('rpath')
#	|| err(1, "pledge: $!");

# compute checksums
my %metadata;
$metadata{'package'} = sha256_file_hex($archive);
$metadata{'files'}   = generate_checksum_files();

# write to checksum
my $json = JSON::PP->new;
print $fchecksum $json->encode(\%metadata);

close($fchecksum);
exit 0;
