$NetBSD: patch-collector_cpufreq__solaris.go,v 1.1 2019/05/22 11:54:06 jperkin Exp $

Fix SunOS build.

--- collector/cpufreq_solaris.go.orig	2019-05-09 18:19:12.000000000 +0000
+++ collector/cpufreq_solaris.go
@@ -36,7 +36,7 @@ func init() {
 	registerCollector("cpufreq", defaultEnabled, NewCpuFreqCollector)
 }
 
-func NewFreqCpuCollector() (Collector, error) {
+func NewCpuFreqCollector() (Collector, error) {
 	return &cpuFreqCollector{
 		cpuFreq: prometheus.NewDesc(
 			prometheus.BuildFQName(namespace, cpuCollectorSubsystem, "frequency_hertz"),
@@ -51,7 +51,7 @@ func NewFreqCpuCollector() (Collector, e
 	}, nil
 }
 
-func (c *cpuCollector) Update(ch chan<- prometheus.Metric) error {
+func (c *cpuFreqCollector) Update(ch chan<- prometheus.Metric) error {
 	ncpus := C.sysconf(C._SC_NPROCESSORS_ONLN)
 
 	tok, err := kstat.Open()
