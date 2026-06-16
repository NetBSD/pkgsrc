$NetBSD: patch-cpan_Socket_Socket.xs,v 1.3 2026/06/16 07:12:10 wiz Exp $

Pull security fix from 2.041

[BUGFIXES]
* Fix reuse of `STRLEN len` variable in pack_ip_mreq_source()

https://github.com/Perl/perl5/commit/de19a0b0ad1900fef976c5c1400bd8f11ec6c6cb.patch

--- cpan/Socket/Socket.xs.orig	2026-01-18 17:50:03.000000000 +0000
+++ cpan/Socket/Socket.xs
@@ -1272,26 +1272,35 @@ pack_ip_mreq(multiaddr, interface=&PL_sv_undef)
         struct ip_mreq mreq;
         char * multiaddrbytes;
         char * interfacebytes;
-        STRLEN len;
-        if (DO_UTF8(multiaddr) && !sv_utf8_downgrade(multiaddr, 1))
-            croak("Wide character in %s", "Socket::pack_ip_mreq");
-        multiaddrbytes = SvPVbyte(multiaddr, len);
-        if (len != sizeof(mreq.imr_multiaddr))
-            croak("Bad arg length %s, length is %" UVuf ", should be %" UVuf,
-                    "Socket::pack_ip_mreq", (UV)len, (UV)sizeof(mreq.imr_multiaddr));
+
+        {
+            if (DO_UTF8(multiaddr) && !sv_utf8_downgrade(multiaddr, 1))
+                croak("Wide character in %s", "Socket::pack_ip_mreq");
+
+            STRLEN len;
+            multiaddrbytes = SvPVbyte(multiaddr, len);
+            if (len != sizeof(mreq.imr_multiaddr))
+                croak("Bad arg length %s, length is %" UVuf ", should be %" UVuf,
+                        "Socket::pack_ip_mreq", (UV)len, (UV)sizeof(mreq.imr_multiaddr));
+        }
+
         Zero(&mreq, sizeof(mreq), char);
         Copy(multiaddrbytes, &mreq.imr_multiaddr, sizeof(mreq.imr_multiaddr), char);
         if(SvOK(interface)) {
             if (DO_UTF8(interface) && !sv_utf8_downgrade(interface, 1))
                 croak("Wide character in %s", "Socket::pack_ip_mreq");
+
+            STRLEN len;
             interfacebytes = SvPVbyte(interface, len);
             if (len != sizeof(mreq.imr_interface))
                 croak("Bad arg length %s, length is %" UVuf ", should be %" UVuf,
                         "Socket::pack_ip_mreq", (UV)len, (UV)sizeof(mreq.imr_interface));
+
             Copy(interfacebytes, &mreq.imr_interface, sizeof(mreq.imr_interface), char);
         }
         else
             mreq.imr_interface.s_addr = INADDR_ANY;
+
         ST(0) = sv_2mortal(newSVpvn((char *)&mreq, sizeof(mreq)));
 #else
         not_here("pack_ip_mreq");
@@ -1331,25 +1340,38 @@ pack_ip_mreq_source(multiaddr, source, interface=&PL_s
         char * multiaddrbytes;
         char * sourcebytes;
         char * interfacebytes;
-        STRLEN len;
-        if (DO_UTF8(multiaddr) && !sv_utf8_downgrade(multiaddr, 1))
-            croak("Wide character in %s", "Socket::pack_ip_mreq_source");
-        multiaddrbytes = SvPVbyte(multiaddr, len);
-        if (len != sizeof(mreq.imr_multiaddr))
-            croak("Bad arg length %s, length is %" UVuf ", should be %" UVuf,
-                    "Socket::pack_ip_mreq", (UV)len, (UV)sizeof(mreq.imr_multiaddr));
-        if (DO_UTF8(source) && !sv_utf8_downgrade(source, 1))
-            croak("Wide character in %s", "Socket::pack_ip_mreq_source");
-        if (len != sizeof(mreq.imr_sourceaddr))
-            croak("Bad arg length %s, length is %" UVuf ", should be %" UVuf,
-                    "Socket::pack_ip_mreq", (UV)len, (UV)sizeof(mreq.imr_sourceaddr));
-        sourcebytes = SvPVbyte(source, len);
+
+        {
+            if (DO_UTF8(multiaddr) && !sv_utf8_downgrade(multiaddr, 1))
+                croak("Wide character in %s", "Socket::pack_ip_mreq_source");
+
+            STRLEN len;
+            multiaddrbytes = SvPVbyte(multiaddr, len);
+            if (len != sizeof(mreq.imr_multiaddr))
+                croak("Bad arg length %s, length is %" UVuf ", should be %" UVuf,
+                        "Socket::pack_ip_mreq", (UV)len, (UV)sizeof(mreq.imr_multiaddr));
+        }
+
+        {
+            if (DO_UTF8(source) && !sv_utf8_downgrade(source, 1))
+                croak("Wide character in %s", "Socket::pack_ip_mreq_source");
+
+            STRLEN len;
+            sourcebytes = SvPVbyte(source, len);
+            if (len != sizeof(mreq.imr_sourceaddr))
+                croak("Bad arg length %s, length is %" UVuf ", should be %" UVuf,
+                        "Socket::pack_ip_mreq", (UV)len, (UV)sizeof(mreq.imr_sourceaddr));
+        }
+
         Zero(&mreq, sizeof(mreq), char);
         Copy(multiaddrbytes, &mreq.imr_multiaddr, sizeof(mreq.imr_multiaddr), char);
         Copy(sourcebytes, &mreq.imr_sourceaddr, sizeof(mreq.imr_sourceaddr), char);
+
         if(SvOK(interface)) {
             if (DO_UTF8(interface) && !sv_utf8_downgrade(interface, 1))
                 croak("Wide character in %s", "Socket::pack_ip_mreq");
+
+            STRLEN len;
             interfacebytes = SvPVbyte(interface, len);
             if (len != sizeof(mreq.imr_interface))
                 croak("Bad arg length %s, length is %" UVuf ", should be %" UVuf,
@@ -1358,6 +1380,7 @@ pack_ip_mreq_source(multiaddr, source, interface=&PL_s
         }
         else
             mreq.imr_interface.s_addr = INADDR_ANY;
+
         ST(0) = sv_2mortal(newSVpvn((char *)&mreq, sizeof(mreq)));
 #else
         PERL_UNUSED_VAR(multiaddr);
@@ -1398,16 +1421,22 @@ pack_ipv6_mreq(multiaddr, ifindex)
 #ifdef HAS_IPV6_MREQ
         struct ipv6_mreq mreq;
         char * multiaddrbytes;
-        STRLEN len;
-        if (DO_UTF8(multiaddr) && !sv_utf8_downgrade(multiaddr, 1))
-            croak("Wide character in %s", "Socket::pack_ipv6_mreq");
-        multiaddrbytes = SvPVbyte(multiaddr, len);
-        if (len != sizeof(mreq.ipv6mr_multiaddr))
-            croak("Bad arg length %s, length is %" UVuf ", should be %" UVuf,
-                    "Socket::pack_ipv6_mreq", (UV)len, (UV)sizeof(mreq.ipv6mr_multiaddr));
+
+        {
+            if (DO_UTF8(multiaddr) && !sv_utf8_downgrade(multiaddr, 1))
+                croak("Wide character in %s", "Socket::pack_ipv6_mreq");
+
+            STRLEN len;
+            multiaddrbytes = SvPVbyte(multiaddr, len);
+            if (len != sizeof(mreq.ipv6mr_multiaddr))
+                croak("Bad arg length %s, length is %" UVuf ", should be %" UVuf,
+                        "Socket::pack_ipv6_mreq", (UV)len, (UV)sizeof(mreq.ipv6mr_multiaddr));
+        }
+
         Zero(&mreq, sizeof(mreq), char);
         Copy(multiaddrbytes, &mreq.ipv6mr_multiaddr, sizeof(mreq.ipv6mr_multiaddr), char);
         mreq.ipv6mr_interface = ifindex;
+
         ST(0) = sv_2mortal(newSVpvn((char *)&mreq, sizeof(mreq)));
 #else
         PERL_UNUSED_VAR(multiaddr);
