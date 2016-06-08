$NetBSD: patch-dist_Carp_lib_Carp.pm,v 1.1 2016/06/08 17:39:30 he Exp $

Apply workaround from https://rt.cpan.org/Public/Bug/Display.html?id=72467

--- dist/Carp/lib/Carp.pm.orig	2016-04-06 12:31:16.000000000 +0000
+++ dist/Carp/lib/Carp.pm
@@ -226,7 +226,11 @@ sub caller_info {
                 = "** Incomplete caller override detected$where; \@DB::args were not set **";
         }
         else {
-            @args = @DB::args;
+            @args = map {
+		local $@;
+		my $tmp = eval { Carp::format_arg($_) };
+		defined($tmp) ? $tmp : 'unknown';
+	    } @DB::args;
             my $overflow;
             if ( $MaxArgNums and @args > $MaxArgNums )
             {    # More than we want to show?
