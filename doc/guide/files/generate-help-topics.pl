#! perl
# $NetBSD: generate-help-topics.pl,v 1.1 2019/04/28 15:22:24 rillig Exp $

use strict;
use warnings;

my $tmpl_file = "help-topics.tmpl.xml";
my $data_file = "help-topics.data";
my $out_file  = "help-topics.xml";

sub read_topics() {
	my @xmltopics;
	open(my $topics, "<", $data_file) or die;
	my $header1 = <$topics>;
	my $header2 = <$topics>;

	while (defined(my $topic = <$topics>)) {
		chomp($topic);
		$topic =~ s,&,\&amp;,g;
		$topic =~ s,<,\&lt;,g;
		push(@xmltopics, $topic);
	}

	close($topics) or die;
	return @xmltopics;
}

sub merge() {
	open(my $tmpl, "<", $tmpl_file) or die;
	open(my $out, ">", "$out_file.tmp") or die;

	while (defined(my $tmpl_line = <$tmpl>)) {
		if ($tmpl_line =~ /\@topic\@/) {
			foreach my $xmltopic (read_topics()) {
				my $line = $tmpl_line;
				$line =~ s,\@topic\@,$xmltopic,e;
				print $out ($line);
			}
		} else {
			print $out ($tmpl_line);
		}
	}
	close($tmpl) or die;
	close($out) or die;

	rename("$out_file.tmp", $out_file) or die;
}

merge();
