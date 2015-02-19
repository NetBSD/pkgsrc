$NetBSD: patch-etc_exabgp_processes_healthcheck.py,v 1.2 2015/02/19 12:23:52 he Exp $

Also match interface alias addresses, and spaces at the front
are already removed after strip().

--- etc/exabgp/processes/healthcheck.py.orig	2014-03-25 19:39:16.000000000 +0000
+++ etc/exabgp/processes/healthcheck.py
@@ -222,7 +222,7 @@ def loopback_ips(label):
         cmd = subprocess.Popen("/sbin/ip -o address show dev lo".split(), shell=False, stdout=subprocess.PIPE)
     else:
         # Try with ifconfig
-        ipre = re.compile(r"^\s+inet6?\s+(?P<ip>[\da-f.:]+)\s+(?:netmask 0x(?P<netmask>[0-9a-f]+)|prefixlen (?P<mask>\d+)).*")
+        ipre = re.compile(r"^inet6?\s+(alias )?(?P<ip>[\da-f.:]+)\s+(?:netmask 0x(?P<netmask>[0-9a-f]+)|prefixlen (?P<mask>\d+)).*")
         cmd = subprocess.Popen("/sbin/ifconfig lo0".split(), shell=False, stdout=subprocess.PIPE)
         labelre = re.compile(r"")
     for line in cmd.stdout:
