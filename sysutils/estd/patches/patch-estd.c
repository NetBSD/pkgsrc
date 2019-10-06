$NetBSD: patch-estd.c,v 1.2 2019/10/06 11:35:16 jmcneill Exp $

- Removed useless "estd: Forked" message
- Add support for generic multi-domain frequency controls

--- estd.c.orig	2015-02-18 21:38:03.000000000 +0000
+++ estd.c
@@ -58,8 +58,9 @@
 #define TECH_INTREPID 4
 #define TECH_LOONGSON 5
 #define TECH_ROCKCHIP 6
-#define TECH_GENERIC 7
-#define TECH_MAX 7
+#define TECH_GENERIC_MD 7
+#define TECH_GENERIC 8
+#define TECH_MAX 8
  
 /* this is ugly, but... <shrug> */
 #define MAX_FREQS 32
@@ -128,6 +129,7 @@ static char	*techdesc[TECH_MAX + 1] = {"
 				"Intrepid",
 				"Loongson",
 				"Rockchip",
+				"Generic Multi-domain",
 				"Generic"
 				};
 static char	*freqctl[TECH_MAX + 1] = {	"",	
@@ -137,6 +139,7 @@ static char	*freqctl[TECH_MAX + 1] = {	"
 				"machdep.intrepid.frequency.available",
 				"machdep.loongson.frequency.available",
 				"machdep.cpu.frequency.available",
+				"machdep.cpufreq.cpu0.available",
 				"machdep.frequency.available"
 				};
 static char	*setctl[TECH_MAX + 1] = {	"",
@@ -146,6 +149,7 @@ static char	*setctl[TECH_MAX + 1] = {	""
 				"machdep.intrepid.frequency.target",
 				"machdep.loongson.frequency.target",
 				"machdep.cpu.frequency.target",
+				"machdep.cpufreq.cpu0.target",
 				"machdep.frequency.current"
 				};
 
@@ -234,6 +238,63 @@ acpi_init()
 }
 
 
+int
+generic_md_init_cpu(int d, int cpu)
+{
+	char name[256];
+	char current[SYSCTLBUF];
+	char *mp;
+	size_t currentsize = SYSCTLBUF;
+	int i;
+
+	snprintf(name, sizeof(name), "machdep.cpufreq.cpu%d.current", cpu);
+	if (sysctlbyname(name, &current, &currentsize, NULL, 0) < 0) {
+		if (d > 0) {
+			/* Assume this CPU is a member of the previous domain */
+			domain[d-1].cpus[domain[d-1].ncpus++] = cpu;
+		}
+		return 1;
+	}
+
+	ndomains = d + 1;
+	domain = realloc(domain, ndomains * sizeof(struct domain));
+	if (domain == NULL) {
+		fprintf(stderr, "estd: realloc failed (errno %d)\n", errno);
+		exit(1);
+	}
+	memset(&domain[d], 0, sizeof(struct domain));
+
+	domain[d].ncpus = 1;
+	domain[d].cpus = ecalloc(ncpus, sizeof(int));
+	domain[d].cpus[0] = cpu;
+
+	asprintf(&domain[d].freqctl, "machdep.cpufreq.cpu%d.available", cpu);
+	asprintf(&domain[d].setctl, "machdep.cpufreq.cpu%d.target", cpu);
+	if (domain[d].setctl == NULL || domain[d].freqctl == NULL) {
+		fprintf(stderr, "estd: asprintf failed\n");
+		exit(1);
+	}
+
+	if ((!daemonize) && (verbose))
+		for (i = 0; i < domain[d].ncpus; i++)
+			printf("estd: domain %d: member %d\n", d, domain[d].cpus[i]);
+
+	return 0;
+}
+
+int
+generic_md_init()
+{
+	int d = 0, cpu;
+
+	for (cpu = 0; cpu < ncpus; cpu++)
+		if (generic_md_init_cpu(d, cpu) == 0)
+			d++;
+
+	return d > 0 ? 0 : 1;
+}
+
+
 /* returns cpu-usage in percent, mean over the sleep-interval or -1 if an error occured */
 #if defined(__DragonFly__)
 int
@@ -308,8 +369,10 @@ get_cpuusage(int d)
 	int		cpu_of_max = 0;
 	int		cpu;
 	int             i;
+	int		n;
 
-	for (cpu = 0; cpu < ncpus; cpu++) {
+	for (n = 0; n < domain[d].ncpus; n++) {
+		cpu = domain[d].cpus[n];
 		u_int64_t total_time = 0;
 
 		for (i = 0; i < CPUSTATES; i++) {
@@ -401,7 +464,7 @@ main(int argc, char *argv[])
 	int             i;
 	char            frequencies[SYSCTLBUF];	/* XXX Ugly */
 	char           *fp;
-	size_t          freqsize = SYSCTLBUF;
+	size_t          freqsize;
 	int	            curstrat = strategy;
 	int             d;
 	FILE           *fexists;
@@ -410,7 +473,7 @@ main(int argc, char *argv[])
 #endif
 
 	/* get command-line options */
-	while ((ch = getopt(argc, argv, "vfdonACEGILPasbp:h:l:g:m:M:")) != -1)
+	while ((ch = getopt(argc, argv, "vfdonACDEGILPasbp:h:l:g:m:M:")) != -1)
 		switch (ch) {
 		case 'v':
 			version();
@@ -438,6 +501,9 @@ main(int argc, char *argv[])
 			 fprintf(stderr, "-C not available under DragonFly\n");
 			 exit(1);
 			#endif
+		case 'D':
+			tech = TECH_GENERIC_MD;
+			break;
 		case 'E':
 			tech = TECH_EST;
 			break;
@@ -516,6 +582,7 @@ main(int argc, char *argv[])
 	/* try to guess cpu-scaling technology */
 	if (tech == TECH_UNKNOWN) {
 		for (tech = 1; tech <= TECH_MAX; tech++) {
+			freqsize = SYSCTLBUF;
 			if (sysctlbyname(freqctl[tech], &frequencies, &freqsize, NULL, 0) >= 0) break;
 		}
 		if (tech > TECH_MAX) {
@@ -529,6 +596,11 @@ main(int argc, char *argv[])
 			fprintf(stderr, "estd: Cannot ACPI P-States\n");
 			exit(1);
 		}
+	} else if (tech == TECH_GENERIC_MD) {
+		if (generic_md_init()) {
+			fprintf(stderr, "estd: Cannot init generic multi-domain support\n");
+			exit(1);
+		}
 	} else {
 		domain[0].freqctl = freqctl[tech];
 		domain[0].setctl = setctl[tech];
@@ -552,6 +624,7 @@ main(int argc, char *argv[])
 	/* for each cpu domain... */
 	for (d = 0; d < ndomains; d++) {
 		/* get supported frequencies... */
+		freqsize = SYSCTLBUF;
 		if (sysctlbyname(domain[d].freqctl, &frequencies, &freqsize, NULL, 0) < 0) {
 			fprintf(stderr, "estd: Cannot get supported frequencies (maybe you forced the wrong CPU-scaling technology?)\n");
 			exit(1);
@@ -588,7 +661,11 @@ main(int argc, char *argv[])
 	if (listfreq) {
 		printf("Supported frequencies (%s Mode):\n",techdesc[tech]);
 		for (d = 0; d < ndomains; d++) {
-			printf("Domain %d:\n", d);
+			printf("Domain %d:", d);
+			for (i = 0; i < domain[d].ncpus; i++) {
+				printf(" cpu%d", domain[d].cpus[i]);
+			}
+			printf("\n");
 			for (i = 0; i < domain[d].nfreqs; i++) {
 				printf("%i MHz\n", domain[d].freqtab[i]);
 			}
@@ -626,7 +703,6 @@ main(int argc, char *argv[])
 	/* all ok, here we go */
 	if (daemonize) {
 		if (fork()) {
-			printf("estd: Forked\n");
 			exit(0);
 		}
 	} else {
