$NetBSD: patch-op__server.pl,v 1.1 2022/09/26 05:22:23 jnemeth Exp $

* fixup obsolete PERL

--- op_server.pl.orig	2009-06-22 18:06:11.000000000 +0000
+++ op_server.pl
@@ -2068,7 +2068,7 @@ sub generate_linked_buttons_list {
     my ( undef, $contexto1 ) = split( /\&/, $nroboton );
     if ( !defined($contexto1) ) { $contexto1 = ""; }
 
-    if ( defined( @{ $linkbot{"$nroboton"} } ) ) {
+    if ( $linkbot{"$nroboton"} ) {
         log_debug( "$heading Esta definido linkbot {$nroboton}", 32 ) if DEBUG;
         foreach ( @{ $linkbot{"$nroboton"} } ) {
             log_debug( "$heading y contiene $_", 32 ) if DEBUG;
@@ -2152,7 +2152,7 @@ sub erase_all_sessions_from_channel {
     delete $monitoring{$canalsesion};
     if ( keys(%cache_hit) ) {
         for ( keys %cache_hit ) {
-            if ( defined( @{ $cache_hit{$_} } ) ) {
+            if ( $cache_hit{$_} ) {
                 foreach my $val ( @{ $cache_hit{$_} } ) {
                     if ( $val eq $canal ) {
                         log_debug( "$heading borro cache $_", 128 ) if DEBUG;
@@ -2195,7 +2195,7 @@ sub erase_all_sessions_from_channel {
 
         if ( keys(%linkbot) ) {
             for ( keys %linkbot ) {
-                if ( defined( @{ $linkbot{$_} } ) ) {
+                if ( $linkbot{$_} ) {
                     my @final = ();
                     foreach my $val ( @{ $linkbot{$_} } ) {
                         log_debug( "$heading linkbot($_) ne $val ?", 64 ) if DEBUG;
@@ -2720,7 +2720,7 @@ sub procesa_bloque {
     my $blaque             = shift;
     my $socket             = shift;
     my $astmanproxy_server = shift;
-    my %bloque             = %$blaque if defined(%$blaque);
+    my %bloque             = %$blaque if %$blaque;
 
     my %hash_temporal = ();
     my $evento        = "";
@@ -3125,9 +3125,9 @@ sub procesa_bloque {
             }
 
             my $tempval = $config->{$contexto}{'attendant_failure_redirect_to'};
-            $tempval =~ s/\${CHANNEL}/$hash_temporal{Channel}/g;
-            $tempval =~ s/\${EXTEN}/$part_ext[0]/g;
-            $tempval =~ s/\${CONTEXT}/$part_ext[1]/g;
+            $tempval =~ s/\$\{CHANNEL}/$hash_temporal{Channel}/g;
+            $tempval =~ s/\$\{EXTEN}/$part_ext[0]/g;
+            $tempval =~ s/\$\{CONTEXT}/$part_ext[1]/g;
 
             if ( $tempval =~ m/\@/ ) {
                 ( $dst_exten, $dst_context ) = split( /\@/, $tempval, 2 );
@@ -3254,15 +3254,15 @@ sub procesa_bloque {
 
                 if ( $srv == $hash_temporal{Server} && "SIP/$chan_name" =~ m/$match/ ) {
                     while ( ( $key, $val ) = each(%tmphash) ) {
-                        $val =~ s/\${CONTEXT}/$ctx/g;
-                        $val =~ s/\${CALLERID}/$calid/g;
-                        $val =~ s/\${CLIDNUM}/$calidnum/g;
-                        $val =~ s/\${CLIDNAME}/$calidname/g;
-                        $val =~ s/\${VOICEMAILBOX}/$voicemailbox/g;
-                        $val =~ s/\${VOICEMAILBOXNUM}/$voicemailboxnum/g;
-                        $val =~ s/\${VOICEMAILBOXCONTEXT}/$voicemailboxcontext/g;
-                        $val =~ s/\${ACCOUNTCODE}/$accode/g;
-                        $val =~ s/\${CHANNEL}/$chan_name/g;
+                        $val =~ s/\$\{CONTEXT}/$ctx/g;
+                        $val =~ s/\$\{CALLERID}/$calid/g;
+                        $val =~ s/\$\{CLIDNUM}/$calidnum/g;
+                        $val =~ s/\$\{CLIDNAME}/$calidname/g;
+                        $val =~ s/\$\{VOICEMAILBOX}/$voicemailbox/g;
+                        $val =~ s/\$\{VOICEMAILBOXNUM}/$voicemailboxnum/g;
+                        $val =~ s/\$\{VOICEMAILBOXCONTEXT}/$voicemailboxcontext/g;
+                        $val =~ s/\$\{ACCOUNTCODE}/$accode/g;
+                        $val =~ s/\$\{CHANNEL}/$chan_name/g;
                         $autosip{"$server^$chan_name"}{$key} = $val;
                     }
                     $autosip{"$server^$chan_name"}{channel}    = "SIP/$chan_name";
@@ -3435,7 +3435,7 @@ sub procesa_bloque {
             my $item_temp = $item;
             my $datoon    = "";
             my $datooff   = "";
-            $item_temp =~ s/\${value}/$valor/g;
+            $item_temp =~ s/\$\{value}/$valor/g;
             my ( $comando, $datos ) = split( /=/, $item_temp );
             if ( $datos =~ /\|/ ) {
                 ( $datoon, $datooff ) = split( /\|/, $datos );
@@ -5805,7 +5805,7 @@ sub digest_event_block {
                             if ( !defined($contexto1) ) { $contexto1 = ""; }
                             my $listabotones = "";
 
-                            if ( !defined( @{ $linkbot{"$server^$canal"} } ) ) {
+                            if ( ! $linkbot{"$server^$canal"} ) {
                                 push @{ $linkbot{"$server^$canal"} }, "";
                                 pop @{ $linkbot{"$server^$canal"} };
                                 log_debug( "$heading DEFINIENDO linkbot ($server^$canal)", 256 ) if DEBUG;
@@ -5987,7 +5987,7 @@ sub digest_event_block {
                                 if ( $canalid !~ /^Agent/ ) {
 
                                     # settimer agent needs to be discarded
-                                    if ( !defined( @{ $sesbot{$interno} } ) ) {
+                                    if ( ! $sesbot{$interno} ) {
                                         push @{ $sesbot{$interno} }, "";
                                         pop @{ $sesbot{$interno} };
                                     }
@@ -8269,12 +8269,12 @@ sub compute_monitoring_filename {
         }
         $hasha{$key} = $val;
     }
-    $filename =~ s/\${CLIDNAME}/$hasha{CLIDNAME}/gi;
-    $filename =~ s/\${CLIDNUM}/$hasha{CLIDNUM}/gi;
-    $filename =~ s/\${CLID}/$hasha{CLID}/gi;
-    $filename =~ s/\${UNIQUEID}/$hasha{UNIQUEID}/gi;
-    $filename =~ s/\${CHANNEL}/$hasha{CHANNEL}/gi;
-    $filename =~ s/\${LINK}/$hasha{LINK}/gi;
+    $filename =~ s/\$\{CLIDNAME}/$hasha{CLIDNAME}/gi;
+    $filename =~ s/\$\{CLIDNUM}/$hasha{CLIDNUM}/gi;
+    $filename =~ s/\$\{CLID}/$hasha{CLID}/gi;
+    $filename =~ s/\$\{UNIQUEID}/$hasha{UNIQUEID}/gi;
+    $filename =~ s/\$\{CHANNEL}/$hasha{CHANNEL}/gi;
+    $filename =~ s/\$\{LINK}/$hasha{LINK}/gi;
     $filename = formatdate($filename);
     $filename =~ s/\//-/gi;
     push @return, $filename;
@@ -8479,7 +8479,7 @@ sub first_client_status {
         }
         if ( keys(%botonqueuemember) ) {
             for $interno ( keys %botonqueuemember ) {
-                if ( defined( @{ $botonqueuemember{$interno} } ) ) {
+                if ( $botonqueuemember{$interno} ) {
                     my %temphash = ();
                     foreach my $val ( @{ $botonqueuemember{$interno} } ) {
                         my @datos = split( /\|/, $val );
@@ -9700,7 +9700,7 @@ sub format_clid {
     }
 
     $devuelve = join( "", reverse @result );
-    $devuelve =~ s/\${CLIDNAME}/$name/gi;
+    $devuelve =~ s/\$\{CLIDNAME}/$name/gi;
     return $devuelve;
 }
 
@@ -10449,7 +10449,7 @@ sub print_cachehit {
             for ( keys %cache_hit ) {
                 print "key $_\n";
 
-                if ( defined( @{ $cache_hit{$_} } ) ) {
+                if ( $cache_hit{$_} ) {
                     my @final = ();
                     foreach my $val ( @{ $cache_hit{$_} } ) {
                         print "\tcache_hit($_) = $val\n";
@@ -10471,7 +10471,7 @@ sub print_linkbot {
         print "---------------------------------------------------\n";
         if ( keys(%linkbot) ) {
             for ( keys %linkbot ) {
-                if ( defined( @{ $linkbot{$_} } ) ) {
+                if ( $linkbot{$_} ) {
                     my @final = ();
                     foreach my $val ( @{ $linkbot{$_} } ) {
                         print "\tlinkbot($_) = $val\n";
@@ -10495,7 +10495,7 @@ sub print_sesbot {
         print "---------------------------------------------------\n";
         if ( keys(%sesbot) ) {
             for ( keys %sesbot ) {
-                if ( defined( @{ $sesbot{$_} } ) ) {
+                if ( $sesbot{$_} ) {
                     my @final = ();
                     foreach my $val ( @{ $sesbot{$_} } ) {
                         print "\tsesbot($_) = $val\n";
