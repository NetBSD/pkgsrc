$NetBSD: patch-kpdf_impl_SVGAnimationElementImpl.cc,v 1.1 2014/01/09 20:11:27 jperkin Exp $

Avoid ambiguous function call.

--- ksvg/impl/SVGAnimationElementImpl.cc.orig	2005-11-08 22:25:43.000000000 +0000
+++ ksvg/impl/SVGAnimationElementImpl.cc
@@ -100,7 +100,7 @@ double SVGAnimationElementImpl::parseClo
 		{
 			QString temp = parse.mid(9, 2);
 			milliseconds = temp.toUInt();
-			result += (milliseconds * (1 / pow(10.0, temp.length())));
+			result += (milliseconds * (1 / pow(10.0, (double)temp.length())));
 		}
 	}
 	else if(doublePointOne != -1 && doublePointTwo == -1) // Spec: "Partial clock values"
@@ -115,7 +115,7 @@ double SVGAnimationElementImpl::parseClo
 		{
 			QString temp = parse.mid(6, 2);
 			milliseconds = temp.toUInt();
-			result += (milliseconds * (1 / pow(10.0, temp.length())));
+			result += (milliseconds * (1 / pow(10.0, (double)temp.length())));
 		}
 	}
 	else // Spec: "Timecount values"
@@ -130,7 +130,7 @@ double SVGAnimationElementImpl::parseClo
 			{
 				result = parse.mid(0, dotPosition).toUInt() * 3600;
 				QString temp = parse.mid(dotPosition + 1, parse.length() - dotPosition - 2);
-				result += (3600.0 * temp.toUInt()) * (1 / pow(10.0, temp.length()));
+				result += (3600.0 * temp.toUInt()) * (1 / pow(10.0, (double)temp.length()));
 			}
 		}
 		else if(parse.endsWith("min"))
@@ -141,7 +141,7 @@ double SVGAnimationElementImpl::parseClo
 			{
 				result = parse.mid(0, dotPosition).toUInt() * 60;
 				QString temp = parse.mid(dotPosition + 1, parse.length() - dotPosition - 4);
-				result += (60.0 * temp.toUInt()) * (1 / pow(10.0, temp.length()));
+				result += (60.0 * temp.toUInt()) * (1 / pow(10.0, (double)temp.length()));
 			}
 		}
 		else if(parse.endsWith("ms"))
@@ -152,7 +152,7 @@ double SVGAnimationElementImpl::parseClo
 			{
 				result = parse.mid(0, dotPosition).toUInt() / 1000.0;
 				QString temp = parse.mid(dotPosition + 1, parse.length() - dotPosition - 3);
-				result += (temp.toUInt() / 1000.0) * (1 / pow(10.0, temp.length()));
+				result += (temp.toUInt() / 1000.0) * (1 / pow(10.0, (double)temp.length()));
 			}
 		}
 		else if(parse.endsWith("s"))
@@ -163,7 +163,7 @@ double SVGAnimationElementImpl::parseClo
 			{
 				result = parse.mid(0, dotPosition).toUInt();
 				QString temp = parse.mid(dotPosition + 1, parse.length() - dotPosition - 2);
-				result += temp.toUInt() * (1 / pow(10.0, temp.length()));
+				result += temp.toUInt() * (1 / pow(10.0, (double)temp.length()));
 			}
 		}
 		else
