$NetBSD: patch-include_pqxx_largeobject.hxx,v 1.1 2012/11/16 00:41:33 joerg Exp $

--- include/pqxx/largeobject.hxx.orig	2012-11-15 13:15:39.000000000 +0000
+++ include/pqxx/largeobject.hxx
@@ -382,7 +382,7 @@ protected:
   virtual int sync()
   {
     // setg() sets eback, gptr, egptr
-    setg(this->eback(), this->eback(), this->egptr());
+    this->setg(this->eback(), this->eback(), this->egptr());
     return overflow(EoF());
   }
 
@@ -403,7 +403,7 @@ protected:
     int_type res = 0;
 
     if (pp > pb) res = AdjustEOF(m_Obj.cwrite(pb, pp-pb));
-    setp(m_P, m_P + m_BufSize);
+    this->setp(m_P, m_P + m_BufSize);
 
     // Write that one more character, if it's there.
     if (ch != EoF())
@@ -419,7 +419,7 @@ protected:
     if (!this->gptr()) return EoF();
     char *const eb = this->eback();
     const int res = AdjustEOF(m_Obj.cread(this->eback(), m_BufSize));
-    setg(eb, eb, eb + ((res==EoF()) ? 0 : res));
+    this->setg(eb, eb, eb + ((res==EoF()) ? 0 : res));
     return (!res || (res == EoF())) ? EoF() : *eb;
   }
 
@@ -435,12 +435,12 @@ private:
     if (mode & PGSTD::ios::in)
     {
       m_G = new char_type[m_BufSize];
-      setg(m_G, m_G, m_G);
+      this->setg(m_G, m_G, m_G);
     }
     if (mode & PGSTD::ios::out)
     {
       m_P = new char_type[m_BufSize];
-      setp(m_P, m_P + m_BufSize);
+      this->setp(m_P, m_P + m_BufSize);
     }
   }
 
