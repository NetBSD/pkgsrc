$NetBSD: patch-lib_Message_Field.pm,v 1.1 2013/12/27 12:47:07 is Exp $

--- lib/Mail/Message/Field.pm.orig	2012-01-04 08:35:33.000000000 +0000
+++ lib/Mail/Message/Field.pm
@@ -22,7 +22,7 @@ my $default_wrap_length = 78;
 
 use overload
     qq("") => sub { $_[0]->unfoldedBody }
- , '+0'   => sub { $_[0]->toInt || 0 }
+ , '0+'   => sub { $_[0]->toInt || 0 }
  , bool   => sub {1}
  , cmp    => sub { $_[0]->unfoldedBody cmp "$_[1]" }
  , '<=>'  => sub { $_[2] ? $_[1] <=> $_[0]->toInt : $_[0]->toInt <=> $_[1] }
