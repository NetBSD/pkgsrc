$NetBSD: patch-core_document.cpp,v 1.1 2020/03/29 20:43:53 markd Exp $

https://nvd.nist.gov/vuln/detail/CVE-2020-9359
https://kde.org/info/security/advisory-20200312-1.txt

--- core/document.cpp.orig	2020-01-06 13:55:05.000000000 +0000
+++ core/document.cpp
@@ -4352,7 +4352,8 @@ void Document::processAction( const Acti
                 {
                     const QUrl realUrl = KIO::upUrl(d->m_url).resolved(url);
                     // KRun autodeletes
-                    new KRun( realUrl, d->m_widget );
+                    KRun *r = new KRun( realUrl, d->m_widget );
+		    r->setRunExecutables(false);
                 }
             }
             } break;
