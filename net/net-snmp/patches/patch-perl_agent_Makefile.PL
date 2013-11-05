$NetBSD: patch-perl_agent_Makefile.PL,v 1.1 2013/11/05 17:40:30 joerg Exp $

--- perl/agent/Makefile.PL.orig	2012-10-09 22:28:58.000000000 +0000
+++ perl/agent/Makefile.PL
@@ -79,7 +79,10 @@ sub InitMakeParams {
     else {
 	$opts = NetSNMPGetOpts();
 	$Params{'LDDLFLAGS'} = "$Config{lddlflags} " . `$opts->{'nsconfig'} --ldflags`;
-	$Params{'LIBS'}   = `$opts->{'nsconfig'} --base-agent-libs`;
+	chomp($Params{'LDDLFLAGS'});
+	$Params{'LDDLFLAGS'} = $Params{'LDDLFLAGS'} . " " . $Config{'ccdlflags'};
+	chomp($Params{'LDDLFLAGS'});
+	$Params{'LIBS'} = `$opts->{'nsconfig'} --base-agent-libs`;
 	chomp($Params{'LIBS'});
 	$Params{'CCFLAGS'} = `$opts->{'nsconfig'} --cflags`;
 	chomp($Params{'CCFLAGS'});
