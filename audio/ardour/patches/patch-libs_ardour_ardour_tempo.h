$NetBSD: patch-libs_ardour_ardour_tempo.h,v 1.1 2020/04/12 19:36:26 joerg Exp $

Ensure operators are defined in the namespace of one of the arguments.

--- libs/ardour/ardour/tempo.h.orig	2020-04-11 23:40:21.653152350 +0000
+++ libs/ardour/ardour/tempo.h
@@ -618,11 +618,11 @@ private:
 	MeterSection* copy_metrics_and_point (const Metrics& metrics, Metrics& copy, MeterSection* section) const;
 };
 
-}; /* namespace ARDOUR */
+LIBARDOUR_API std::ostream& operator<< (std::ostream&, const Meter&);
+LIBARDOUR_API std::ostream& operator<< (std::ostream&, const Tempo&);
+LIBARDOUR_API std::ostream& operator<< (std::ostream&, const MetricSection&);
 
-LIBARDOUR_API std::ostream& operator<< (std::ostream&, const ARDOUR::Meter&);
-LIBARDOUR_API std::ostream& operator<< (std::ostream&, const ARDOUR::Tempo&);
-LIBARDOUR_API std::ostream& operator<< (std::ostream&, const ARDOUR::MetricSection&);
+}; /* namespace ARDOUR */
 
 namespace PBD {
 	DEFINE_ENUM_CONVERT (ARDOUR::TempoSection::Type)
