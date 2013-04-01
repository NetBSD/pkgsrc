$NetBSD: patch-make_lib_SDL_Build.pm,v 1.1 2013/04/01 12:09:32 joerg Exp $

--- make/lib/SDL/Build.pm.orig	2013-03-31 15:53:23.000000000 +0000
+++ make/lib/SDL/Build.pm
@@ -137,20 +137,22 @@ sub set_flags
 	{
 		my $sub_file     = $subsystems->{$subsystem}{file}{to};
 		my $sub_includes = join(' ', @{ $includes->{$subsystem} } );
+		my @sdl_compile_flags = split(" ", $sdl_compile);
+		my @sdl_link_flags = split(" ", $sdl_link);
 
 		$file_flags{ $sub_file } = 
 		{
 			extra_compiler_flags =>
 			[
 				@{ $includes->{$subsystem} },
-				$sdl_compile,
+				@sdl_compile_flags,
 				@{ $defines->{$subsystem} },
 				( defined $Config{usethreads} ? ('-DUSE_THREADS', '-fPIC') : '-fPIC' ),
 			],
 			extra_linker_flags => 
 			[
 				@{ $links->{$subsystem}{paths} },
-				$sdl_link,
+				@sdl_link_flags,
 				@{ $links->{$subsystem}{libs} },
 			],
 		},
