$NetBSD: patch-src_control_tools_StrokeHandler.cpp,v 1.1 2019/11/02 14:44:15 nia Exp $

On NetBSD, absolute coordinate changes are reported as an X value followed by a Y value,
which (when moving quickly) leads to a "stepping" effect. Using a Bezier curve fitting
for the points yields a smooth curve in most cases, and does not seem to adversely affect
the user experience (even with a conventional mouse).

--- ./src/control/tools/StrokeHandler.cpp.orig	2019-09-10 05:47:36.000000000 +0000
+++ ./src/control/tools/StrokeHandler.cpp
@@ -115,9 +115,36 @@ bool StrokeHandler::onMotionNotifyEvent(
 	}
 	else
 	{
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+		if (pointCount > 1)
+#else
 		if (pointCount > 0)
+#endif
 		{
 			Point prevPoint(stroke->getPoint(pointCount - 1));
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+			double length, prevLength, t, x, y;
+			Point pprevPoint(stroke->getPoint(pointCount - 2));
+
+			// treat this point as an end point
+			// treat the previous point as a control point and recalculate the "actual" point
+			prevLength = prevPoint.lineLengthTo(pprevPoint);
+			length = prevLength + currentPoint.lineLengthTo(prevPoint);
+			if (length != 0)
+			{
+				t = prevLength/length;
+				// Bezier curve fitting
+				x = (1-t)*(1-t)*pprevPoint.x + 2*t*(1-t)*prevPoint.x + t*t*currentPoint.x;
+				y = (1-t)*(1-t)*pprevPoint.y + 2*t*(1-t)*prevPoint.y + t*t*currentPoint.y;
+				
+				prevPoint = Point(x,y,prevPoint.z);
+				stroke->deletePointsFrom(pointCount-1);
+				stroke->addPoint(prevPoint);
+				stroke->addPoint(currentPoint);
+				currentPoint = prevPoint;
+				prevPoint = pprevPoint;
+			}
+#endif
 
 			Stroke lastSegment;
 
