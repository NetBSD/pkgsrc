$NetBSD: patch-tool_ifdef_get.c,v 1.1 2016/09/28 10:00:27 kamil Exp $

LP64 fixes.

--- tool/ifdef/get.c.orig	2006-07-26 13:00:37.000000000 +0000
+++ tool/ifdef/get.c
@@ -2582,7 +2582,7 @@ struct G__param *libp;
 {
 	char temp[ONELINE],temp1[ONELINE];
 	FILE *fopen();
-	int fp;
+	long fp;
 
 	if(strcmp(funcname,"printf")==0) {
 		/* para[0]:description, para[1~paran-1]: */
@@ -2603,18 +2603,18 @@ struct G__param *libp;
 
 	if(strcmp(funcname,"fclose")==0) {
 		/* para[0]:filepointer */
-		sprintf(result7,"%d",fclose((FILE*)atoi(libp->para[0])));
+		sprintf(result7,"%d",fclose((FILE*)atol(libp->para[0])));
 		return(1);
 	}
 
 	if(strcmp(funcname,"fgets")==0) {
 		/* parameter[0]:varname, para[1]:nchar,para[2]:filepointer */
-		fp=atoi(libp->para[2]);
+		fp=atol(libp->para[2]);
 		sprintf(result7,"%ld"
 			,(long)fgets(temp,atoi(libp->para[1]),(FILE*)fp));
 		G__letvariable(libp->parameter[0]
 			    ,G__add_quotation(temp),&G__global,G__local);
-		sprintf(temp,"%d",fp);
+		sprintf(temp,"%ld",fp);
 		G__letvariable(libp->parameter[1],temp,&G__global,G__local);
 		return(1);
 	}
@@ -2622,7 +2622,7 @@ struct G__param *libp;
 	if(strcmp(funcname,"fprintf")==0) {
 		/* parameter[0]:pointer ,parameter[1]:description, para[2~paran-1]: */
 		G__charformatter(result7,1,libp);
-		fprintf((FILE*)atoi(libp->para[0]),"%s",result7);
+		fprintf((FILE*)atol(libp->para[0]),"%s",result7);
 		strcpy(result7,"");
 		return(1);
 	}
@@ -3553,5 +3553,3 @@ FILE *fp;
 
 	return( c ) ;
 }
-
-
