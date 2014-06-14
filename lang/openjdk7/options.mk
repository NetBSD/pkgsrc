# $NetBSD: options.mk,v 1.5 2014/06/14 22:44:53 ryoon Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openjdk7
PKG_SUPPORTED_OPTIONS=		sun-jre-jce # jdk-zero-vm
PKG_SUGGESTED_OPTIONS=		#

.include "../../mk/bsd.options.mk"

###
### Java(TM) Cryptography Extension (JCE)
###
.if !empty(PKG_OPTIONS:Msun-jre-jce) || make(distinfo) || make(mdi)
JCE_DISTFILE=	UnlimitedJCEPolicyJDK7.zip
DISTFILES+=	${JCE_DISTFILE}
EXTRACT_ONLY+=	${JCE_DISTFILE}
PLIST.jce=	yes
USE_TOOLS+=	pax
#
.  if !exists(${DISTDIR}/${DIST_SUBDIR}/${JCE_DISTFILE})
FETCH_MESSAGE+= "Please download the Java(TM) Cryptography Extension (JCE) Unlimited"
FETCH_MESSAGE+= "Strength Jurisdiction Policy Files 7 '${JCE_DISTFILE}' from:"
FETCH_MESSAGE+= "	http://www.oracle.com/technetwork/java/javase/downloads/jce-7-download-432124.html"
FETCH_MESSAGE+= " and place it in:"
FETCH_MESSAGE+= "       ${DISTDIR}/${DIST_SUBDIR}/${JCE_DISTFILE}"
FETCH_MESSAGE+= ""
FETCH_MESSAGE+= " Then resume this build by running '"${MAKE:Q}"' again."
.  endif
#
post-install:
	cd ${WRKDIR}/UnlimitedJCEPolicy && pax -rw -pp . ${DESTDIR}${JAVA_HOME}/jre/lib/security
.endif

# this option builds a JVM without assembly optimisation. Useful for porting.
# NOTE: This is work in progress.
.if !empty(PKG_OPTIONS:Mjdk-zero-vm)
MAKE_ENV+=	ZERO_BUILD=true
.include "../../devel/libffi/buildlink3.mk"
.endif
