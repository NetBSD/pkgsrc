$NetBSD: patch-Interpreter.cpp,v 1.2 2015/06/10 14:58:50 joerg Exp $

Avoid overlap with std::mutex.

--- Interpreter.cpp.orig	2012-08-06 14:57:58.000000000 +0000
+++ Interpreter.cpp
@@ -69,6 +69,8 @@ using namespace std;
 QMutex keymutex;
 int currentKey;
 
+#define mutex my_mutex
+
 extern QMutex mutex;
 extern QMutex debugmutex;
 extern QWaitCondition waitCond;
@@ -2446,7 +2448,7 @@ Interpreter::execByteCode()
 					poly.drawPolygon(points, pairs);
 					poly.end();
 					if (!fastgraphics) waitForGraphics();
-					delete points;
+					delete[] points;
 				}
 			} else {
 				errornum = ERROR_POLYARRAY;
@@ -2487,7 +2489,7 @@ Interpreter::execByteCode()
 				poly.end();
 	
 				if (!fastgraphics) waitForGraphics();
-				delete points;
+				delete[] points;
 			}
 		}
 		break;
@@ -2538,7 +2540,7 @@ Interpreter::execByteCode()
 						poly.end();
 						if (!fastgraphics) waitForGraphics();
 
-						delete points;
+						delete[] points;
 					}
 				}
 			} else {
@@ -2608,7 +2610,7 @@ Interpreter::execByteCode()
 					poly.end();
 					
 					if (!fastgraphics) waitForGraphics();
-					delete points;
+					delete[] points;
 				}
 			}
 		}
