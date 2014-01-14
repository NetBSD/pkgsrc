$NetBSD: patch-perl_Git_SVN_Editor.pm,v 1.1 2014/01/14 18:49:55 wiz Exp $

[PATCH] git-svn: workaround for a bug in svn serf backend

Subversion serf backend in versions 1.8.5 and below has a bug that the
function creating the descriptor of a file change -- add_file() --
doesn't make a copy of its 3d argument when storing it on the returned
descriptor.  As a result, by the time this field is used (in
transactions of file copying or renaming) it may well be released.

This patch works around this bug, by storing the value to be passed as
the 3d argument to add_file() in a local variable with the same scope as
the file change descriptor, making sure their lifetime is the same.

Cc: Benjamin Pabst <benjamin.pabst85 <at> gmail.com>
Cc: Eric Wong <normalperson <at> yhbt.net>
Signed-off-by: Roman Kagan <rkagan <at> mail.ru>
---
 perl/Git/SVN/Editor.pm | 10 ++++++++--
 1 file changed, 8 insertions(+), 2 deletions(-)

http://permalink.gmane.org/gmane.comp.version-control.git/239690

--- perl/Git/SVN/Editor.pm.orig	2013-12-17 23:46:08.000000000 +0000
+++ perl/Git/SVN/Editor.pm
@@ -304,8 +304,12 @@ sub C {
 	my ($self, $m, $deletions) = @_;
 	my ($dir, $file) = split_path($m->{file_b});
 	my $pbat = $self->ensure_path($dir, $deletions);
+	# workaround for a bug in svn serf backend (v1.8.5 and below):
+	# store 3d argument to ->add_file() in a local variable, to make it
+	# have the same lifetime as $fbat
+	my $upa = $self->url_path($m->{file_a});
 	my $fbat = $self->add_file($self->repo_path($m->{file_b}), $pbat,
-				$self->url_path($m->{file_a}), $self->{r});
+				$upa, $self->{r});
 	print "\tC\t$m->{file_a} => $m->{file_b}\n" unless $::_q;
 	$self->chg_file($fbat, $m);
 	$self->close_file($fbat,undef,$self->{pool});
@@ -323,8 +327,10 @@ sub R {
 	my ($self, $m, $deletions) = @_;
 	my ($dir, $file) = split_path($m->{file_b});
 	my $pbat = $self->ensure_path($dir, $deletions);
+	# workaround for a bug in svn serf backend, see comment in C() above
+	my $upa = $self->url_path($m->{file_a});
 	my $fbat = $self->add_file($self->repo_path($m->{file_b}), $pbat,
-				$self->url_path($m->{file_a}), $self->{r});
+				$upa, $self->{r});
 	print "\tR\t$m->{file_a} => $m->{file_b}\n" unless $::_q;
 	$self->apply_autoprops($file, $fbat);
 	$self->chg_file($fbat, $m);
