#!@PERL@
#
# $NetBSD: msgfmt.pl,v 1.1 2004/04/01 18:33:20 jmmv Exp $
#
# msgfmt.pl - Workaround uses of msgid_plural to work with implementations
#             that don't support it.
#
# Copyright (c) 2004 Julio M. Merino Vidal <jmmv@NetBSD.org>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
# 3. Neither the name of author nor the names of its contributors may
#    be used to endorse or promote products derived from this software
#    without specific prior written permission.
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

# Parse command line.  We copy almost everything as is in the @args array,
# which will be used later when calling the real "msgfmt" utility.  As an
# exception, the file name is transformed to the temporary file we will
# use, and the original one is stored in the $file variable.
@args = ();
$file = "";
$skip = 0;
foreach (@ARGV) {
    if ($skip) {
        $skip = 0;
    } elsif (/^-(a|D|o)$/) {
        $skip = 1;
    } elsif (/^--(alignment|directory|output-file)$/) {
        $skip = 1;
    } elsif (/^[^-]/) {
        $file = $_;
        $_ = "$file.tmp";
    }

    push @args, $_;
}

# Parse the catalog file to convert msgid_plural entries to the "old"
# format, which handles each of the translations independantly.
open INFILE, $file;
open OUTFILE, ">$file.tmp";

$read_plural = 0;
$skip = 0;
@msgid_plural = ();

printf "Fixing plural forms in $file\n";
while (<INFILE>) {
    if (/^msgid_plural/) {
        $read_plural = 1;
        s/^msgid_plural[ \t]+"/"/;
        push @msgid_plural, $_;
    } elsif ($read_plural && /^msgstr\[0\]/) {
        $read_plural = 0;
        s/^msgstr\[0\]/msgstr/;
        print OUTFILE;
    } elsif ($read_plural) {
        push @msgid_plural, $_;
    } elsif (/^msgstr\[1\]/) {
        print OUTFILE "\n";
        print OUTFILE "msgid ";
        foreach $line (@msgid_plural) {
            print OUTFILE "$line";
        }
        s/^msgstr\[1\]/msgstr/;
        print OUTFILE;
        @msgid_plural = ();
    } elsif (/^msgstr\[2\]/) {
    	$skip = 1;
    } elsif (/^[ \t]*$/) {
    	$skip = 0;
        print OUTFILE;
    } elsif (! $skip) {
        print OUTFILE;
    }
}

close OUTFILE;
close INFILE;

# Call the real msgfmt utility, using the temporary file as the source
# catalog.
printf "Running `@MSGFMT@ @args'\n";
$ret = system("@MSGFMT@ @args") >> 8;

if ($ret == 0) {
    unlink "$file.tmp";
}

exit $ret;
