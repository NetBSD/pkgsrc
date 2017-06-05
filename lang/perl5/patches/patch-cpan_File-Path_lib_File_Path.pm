$NetBSD: patch-cpan_File-Path_lib_File_Path.pm,v 1.1 2017/06/05 18:58:44 bsiegert Exp $
OpenBSD 6.1 errata 10, June 04, 2017:

Use fchmod to avoid a race condition in File::Path.  
Fixes CVE-2017-6512.

--- cpan/File-Path/lib/File/Path.pm	5 Feb 2017 00:31:58 -0000
+++ cpan/File-Path/lib/File/Path.pm	1 Jun 2017 22:00:11 -0000
@@ -18,7 +18,7 @@ BEGIN {
 
 use Exporter ();
 use vars qw($VERSION @ISA @EXPORT @EXPORT_OK);
-$VERSION   = '2.12_01';
+$VERSION   = '2.12_02';
 $VERSION   = eval $VERSION;
 @ISA       = qw(Exporter);
 @EXPORT    = qw(mkpath rmtree);
@@ -354,21 +354,32 @@ sub _rmtree {
 
                 # see if we can escalate privileges to get in
                 # (e.g. funny protection mask such as -w- instead of rwx)
-                $perm &= oct '7777';
-                my $nperm = $perm | oct '700';
-                if (
-                    !(
-                           $arg->{safe}
-                        or $nperm == $perm
-                        or chmod( $nperm, $root )
-                    )
-                  )
-                {
-                    _error( $arg,
-                        "cannot make child directory read-write-exec", $canon );
-                    next ROOT_DIR;
+                # This uses fchmod to avoid traversing outside of the proper
+                # location (CVE-2017-6512)
+                my $root_fh;
+                if (open($root_fh, '<', $root)) {
+                    my ($fh_dev, $fh_inode) = (stat $root_fh )[0,1];
+                    $perm &= oct '7777';
+                    my $nperm = $perm | oct '700';
+                    local $@;
+                    if (
+                        !(
+                            $arg->{safe}
+                           or $nperm == $perm
+                           or !-d _
+                           or $fh_dev ne $ldev
+                           or $fh_inode ne $lino
+                           or eval { chmod( $nperm, $root_fh ) }
+                        )
+                      )
+                    {
+                        _error( $arg,
+                            "cannot make child directory read-write-exec", $canon );
+                        next ROOT_DIR;
+                    }
+                    close $root_fh;
                 }
-                elsif ( !chdir($root) ) {
+                if ( !chdir($root) ) {
                     _error( $arg, "cannot chdir to child", $canon );
                     next ROOT_DIR;
                 }
