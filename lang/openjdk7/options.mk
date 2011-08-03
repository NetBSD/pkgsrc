# $NetBSD: options.mk,v 1.2 2011/08/03 13:28:35 obache Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openjdk7
PKG_SUPPORTED_OPTIONS=		sun-jre-jce
PKG_SUGGESTED_OPTIONS=		#

.include "../../mk/bsd.options.mk"

###
### Java(TM) Cryptography Extension (JCE)
###
.if !empty(PKG_OPTIONS:Msun-jre-jce)
JCE_DISTFILE=jce_policy-6.zip
DISTFILES+=	${JCE_DISTFILE}
EXTRACT_ONLY+=	${JCE_DISTFILE}
PLIST.jce=	yes
USE_TOOLS+=	pax
#
.if !exists(${DISTDIR}/${DIST_SUBDIR}/${JCE_DISTFILE})
FETCH_MESSAGE+= "Please download the Java(TM) Cryptography Extension (JCE) Unlimited"
FETCH_MESSAGE+= "Strength Jurisdiction Policy Files 6 '${JCE_DISTFILE}' from:"
FETCH_MESSAGE+= "	http://java.sun.com/javase/downloads/"
FETCH_MESSAGE+= " and place it in:"
FETCH_MESSAGE+= "       ${DISTDIR}/${DIST_SUBDIR}/${JCE_DISTFILE}"
FETCH_MESSAGE+= ""
FETCH_MESSAGE+= " Then resume this build by running '"${MAKE:Q}"' again."
.endif
#
post-install:
	cd ${WRKDIR}/jce ; pax -rw -pp . ${DESTDIR}${JAVA_HOME}/jre/lib/security
.endif
