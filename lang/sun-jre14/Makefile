# $NetBSD: Makefile,v 1.20 2004/10/05 22:09:23 tv Exp $

# Note: Regen distinfo with SUN_JRE14_USE_JCE=YES

DISTNAME=	j2re-1_4_2_05-linux-i586
PKGNAME=	sun-jre14-2.5
PKGREVISION=	1
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) 2 Runtime Environment 1.4.2

SHORT=		JRE

WRKSRC=		${WRKDIR}/j2re1.4.2_05
USE_PKGINSTALL=	yes
JAVA_WRAPPERS=	java keytool orbd policytool rmid rmiregistry \
		servertool tnameserv
OWN_DIRS=	${JAVA_HOME}
OWN_DIRS+=	${JAVA_HOME}/lib
OWN_DIRS+=	${JAVA_HOME}/lib/applet
OWN_DIRS+=	${JAVA_HOME}/lib/images
OWN_DIRS+=	${JAVA_HOME}/lib/images/cursors
OWN_DIRS+=	${JAVA_HOME}/lib/security
SFILES=		content-types.properties	flavormap.properties
SFILES+=	font.properties.Redhat6.1	font.properties
SFILES+=	font.properties.ja.Redhat6.1	font.properties.ja.Redhat6.2
SFILES+=	font.properties.ja.Turbo	font.properties.ja.Turbo6.0
SFILES+=	font.properties.ja		font.properties.zh.Turbo
SFILES+=	images/cursors/cursors.properties	i386/jvm.cfg
SFILES+=	logging.properties		psfont.properties.ja
SFILES+=	psfontj2d.properties		security/java.security
SUPPORT_FILES=	# empty
.for FILE in ${SFILES}
SUPPORT_FILES+=	${JAVA_HOME}/lib/${FILE}.default ${JAVA_HOME}/lib/${FILE}
.endfor

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		SUN_JRE14_USE_JCE
PLIST_SRC=      	${WRKDIR}/PLIST

.if !empty(SUN_JRE14_USE_JCE:M[Yy][Ee][Ss])
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} jce_policy-1_4_2.zip
.endif

do-configure:
	cd ${WRKSRC}/lib; for file in ${SFILES}; do			\
		${MV} -f $$file $$file.default;				\
	done
.if !empty(SUN_JRE14_USE_JCE:M[Yy][Ee][Ss])
	cd ${WRKDIR}/jce ; pax -rw -pe -v . ${WRKSRC}/lib/security
	${SED} 's/@SUN_JRE14_USE_JCE@//' ${PKGDIR}/PLIST > ${PLIST_SRC}
.else
	${SED} '/@SUN_JRE14_USE_JCE@/d' ${PKGDIR}/PLIST > ${PLIST_SRC}
.endif

.include "../../lang/sun-jre14/Makefile.common"
