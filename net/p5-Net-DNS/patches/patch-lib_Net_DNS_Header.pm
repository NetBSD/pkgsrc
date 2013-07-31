$NetBSD: patch-lib_Net_DNS_Header.pm,v 1.1 2013/07/31 09:47:52 he Exp $

Make it possible to tweak the qdcount, ancount, nscount and arcount
header fields, so that fpdns can be allowed to craft particular packets.

--- lib/Net/DNS/Header.pm.orig	2012-12-05 12:03:11.000000000 +0000
+++ lib/Net/DNS/Header.pm
@@ -334,8 +334,9 @@ sub cd {
 =head2 qdcount, zocount
 
     print "# of question records: ", $packet->header->qdcount, "\n";
+    $packet->header->qdcount($n);
 
-Gets the number of records in the question section of the packet.
+Gets or sets the number of records in the question section of the packet.
 In dynamic update packets, this field is known as C<zocount> and refers
 to the number of RRs in the zone section.
 
@@ -347,15 +348,16 @@ sub qdcount {
 	my $self = shift;
 	my $xpkt = $self->{xbody};
 	return $self->{count}[0] || scalar @{$xpkt->{question}} unless @_;
-	carp 'header->qdcount attribute is read-only' unless $warned;
+	$self->{count}[0] = @_;
 }
 
 
 =head2 ancount, prcount
 
     print "# of answer records: ", $packet->header->ancount, "\n";
+    $packet->header->ancount($n);
 
-Gets the number of records in the answer section of the packet.
+Gets or sets the number of records in the answer section of the packet.
 In dynamic update packets, this field is known as C<prcount> and refers
 to the number of RRs in the prerequisite section.
 
@@ -365,15 +367,16 @@ sub ancount {
 	my $self = shift;
 	my $xpkt = $self->{xbody};
 	return $self->{count}[1] || scalar @{$xpkt->{answer}} unless @_;
-	carp 'header->ancount attribute is read-only' unless $warned;
+	$self->{count}[1] = @_;
 }
 
 
 =head2 nscount, upcount
 
     print "# of authority records: ", $packet->header->nscount, "\n";
+    $packet->header->nscount($n);
 
-Gets the number of records in the authority section of the packet.
+Gets or sets the number of records in the authority section of the packet.
 In dynamic update packets, this field is known as C<upcount> and refers
 to the number of RRs in the update section.
 
@@ -383,15 +386,16 @@ sub nscount {
 	my $self = shift;
 	my $xpkt = $self->{xbody};
 	return $self->{count}[2] || scalar @{$xpkt->{authority}} unless @_;
-	carp 'header->nscount attribute is read-only' unless $warned;
+	$self->{count}[2] = @_;
 }
 
 
 =head2 arcount, adcount
 
     print "# of additional records: ", $packet->header->arcount, "\n";
+    $packet->header->arcount($n);
 
-Gets the number of records in the additional section of the packet.
+Gets or sets the number of records in the additional section of the packet.
 In dynamic update packets, this field is known as C<adcount>.
 
 =cut
@@ -400,7 +404,7 @@ sub arcount {
 	my $self = shift;
 	my $xpkt = $self->{xbody};
 	return $self->{count}[3] || scalar @{$xpkt->{additional}} unless @_;
-	carp 'header->arcount attribute is read-only' unless $warned;
+	$self->{count}[3] = @_;
 }
 
 sub zocount { &qdcount; }
