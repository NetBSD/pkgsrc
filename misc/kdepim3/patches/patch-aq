$NetBSD: patch-aq,v 1.5 2011/01/20 11:56:51 markd Exp $

from gentoo bug #282116. fix build with gcc4.4

--- indexlib/memvector.tcc.orig	2008-02-13 09:39:38.000000000 +0000
+++ indexlib/memvector.tcc
@@ -33,7 +33,7 @@ void memvector<T>::resize( size_type n_s
 	data_->resize( n_s * byte_io::byte_lenght<value_type>() + byte_io::byte_lenght<unsigned>() );
 	iterator p_end = end();
 	byte_io::write<unsigned>( data_->rw_base( 0 ), n_s );
-	while ( operator !=<unsigned, unsigned>(p_end, end()) ) {
+	while ( p_end != end() ) {
 		*p_end = value_type();
 		++p_end;
 		
