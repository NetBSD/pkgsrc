$NetBSD: patch-cpan_Archive-Tar_lib_Archive_Tar.pm,v 1.1 2026/05/27 22:35:30 wiz Exp $

Archive::Tar versions before 3.10 for Perl allow memory exhaustion via
attacker controlled entry size field in tar header.
https://github.com/jib/archive-tar-new/commit/f9af01426038e29d9578825a0cd3626946ab08c7.patch

--- cpan/Archive-Tar/lib/Archive/Tar.pm.orig	2026-01-18 16:32:21.000000000 +0000
+++ cpan/Archive-Tar/lib/Archive/Tar.pm
@@ -24,7 +24,7 @@ use vars qw[$DEBUG $error $VERSION $WARN $FOLLOW_SYMLI
 use vars qw[$DEBUG $error $VERSION $WARN $FOLLOW_SYMLINK $CHOWN $CHMOD
             $DO_NOT_USE_PREFIX $HAS_PERLIO $HAS_IO_STRING $SAME_PERMISSIONS
             $INSECURE_EXTRACT_MODE $ZERO_PAD_NUMBERS @ISA @EXPORT $RESOLVE_SYMLINK
-            $EXTRACT_BLOCK_SIZE
+            $EXTRACT_BLOCK_SIZE $MAX_FILE_SIZE
          ];
 
 @ISA                    = qw[Exporter];
@@ -41,6 +41,7 @@ $EXTRACT_BLOCK_SIZE     = 1024 * 1024 * 1024;
 $ZERO_PAD_NUMBERS       = 0;
 $RESOLVE_SYMLINK        = $ENV{'PERL5_AT_RESOLVE_SYMLINK'} || 'speed';
 $EXTRACT_BLOCK_SIZE     = 1024 * 1024 * 1024;
+$MAX_FILE_SIZE          = 1024 * 1024 * 1024;
 
 BEGIN {
     use Config;
@@ -444,6 +445,14 @@ sub _read_tar {
 
             my $block = BLOCK_SIZE->( $entry->size );
 
+            if ( $MAX_FILE_SIZE && $entry->size > $MAX_FILE_SIZE ) {
+                $self->_error( qq[Entry '] . $entry->full_path .
+                    qq[' declared size ] . $entry->size .
+                    qq[ bytes exceeds \$Archive::Tar::MAX_FILE_SIZE ] .
+                    qq[($MAX_FILE_SIZE); refusing to allocate] );
+                next LOOP;
+            }
+
             $data = $entry->get_content_by_ref;
 
 	    my $skip = 0;
@@ -2186,6 +2195,13 @@ extraction may fail with an error.
 cannot be arbitrarily large since some operating systems limit the number of
 bytes that can be written in one call to C<write(2)>, so if this is too large,
 extraction may fail with an error.
+
+=head2 $Archive::Tar::MAX_FILE_SIZE
+
+This variable holds an upper bound on the per-entry declared size that
+C<Archive::Tar> will accept when reading an archive. Entries whose header
+claims a larger size are refused with an error before any read allocation.
+Defaults to 1 GiB. Set to 0 to disable the cap.
 
 =cut
 
