$NetBSD: patch-predict.c,v 1.1 2018/06/04 07:18:47 dbj Exp $

sundry fixes to server mode:
  fix buffer size issue looking for netport
  provide default port if getservbyname fails
  provide default proto if getprotobyname fails
  fix inexplicable incorrect listen call
remove reference to exended ascii symbol for degrees

--- predict.c.orig	2006-05-14 23:19:56.000000000 +0000
+++ predict.c
@@ -172,7 +172,7 @@ double	tsince, jul_epoch, jul_utc, eclip
 	moon_az, moon_el, moon_dx, moon_ra, moon_dec, moon_gha, moon_dv;
 
 char	qthfile[50], tlefile[50], dbfile[50], temp[80], output[25],
-	serial_port[15], resave=0, reload_tle=0, netport[6],
+	serial_port[15], resave=0, reload_tle=0, netport[8],
 	once_per_second=0, ephem[5], sat_sun_status, findsun,
 	calc_squint, database=0, xterm, io_lat='N', io_lon='W';
 
@@ -1984,6 +1984,7 @@ int passivesock(char *service, char *pro
 
 	struct servent *pse;
 	struct protoent *ppe;
+	struct protoent ppedef = { 0, 0, 17 }; // udp
 	struct sockaddr_in sin;
 	int sd, type;
 	
@@ -1996,14 +1997,12 @@ int passivesock(char *service, char *pro
 
 	else if ((sin.sin_port=htons((unsigned short)atoi(service)))==0)
 	{
-		bailout("Can't get service");
-		exit(-1);
+		sin.sin_port=htons(1210);
 	}
 	
 	if ((ppe=getprotobyname(protocol))==0)
 	{
-		bailout("Can't get protocol");
-		exit(-1);
+		ppe = &ppedef;
 	}
 	
 	if (strcmp(protocol,"udp")==0)
@@ -2025,7 +2024,7 @@ int passivesock(char *service, char *pro
 		exit(-1);
 	}
 	
-	if ((type=SOCK_STREAM && listen(s,qlen))<0)
+	if (type==SOCK_STREAM && listen(sd,qlen)<0)
 	{
 		bailout("Listen fail");
 		exit(-1);
@@ -5002,7 +5001,7 @@ char speak;
 		mvprintw(7+tshift,29,"%0.f ",(3600.0*sat_vel)*km2mi);
 		mvprintw(8+tshift,29,"%0.f ",3600.0*sat_vel);
 
-		mvprintw(18+bshift,3,"%+6.2f%c  ",eclipse_depth/deg2rad,176);
+		mvprintw(18+bshift,3,"%+6.2f   ",eclipse_depth/deg2rad);
 		mvprintw(18+bshift,20,"%5.1f",256.0*(phase/twopi));
 		mvprintw(18+bshift,37,"%s",ephem);
 
