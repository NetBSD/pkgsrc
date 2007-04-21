# $NetBSD: Makefile,v 1.40 2007/04/21 20:40:52 rillig Exp $

# Note: Regen distinfo with PKG_DEFAULT_OPTIONS+=sun-jre-jce

DISTNAME=	j2re-1_4_2_14-linux-i586
PKGNAME=	sun-jre14-2.14
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) 2 Runtime Environment 1.4.2

SHORT=		JRE

WRKSRC=		${WRKDIR}/j2re1.4.2_14
JAVA_WRAPPERS=	java keytool orbd policytool rmid rmiregistry \
		servertool tnameserv
REQD_DIRS=	${JAVA_HOME}
REQD_DIRS+=	${JAVA_HOME}/lib
REQD_DIRS+=	${JAVA_HOME}/lib/applet
REQD_DIRS+=	${JAVA_HOME}/lib/images
REQD_DIRS+=	${JAVA_HOME}/lib/images/cursors
REQD_DIRS+=	${JAVA_HOME}/lib/security
SFILES=		content-types.properties	flavormap.properties
SFILES+=	font.properties.Redhat6.1	font.properties
SFILES+=	font.properties.ja.Redhat6.1	font.properties.ja.Redhat6.2
SFILES+=	font.properties.ja.Turbo	font.properties.ja.Turbo6.0
SFILES+=	font.properties.ja		font.properties.zh.Turbo
SFILES+=	images/cursors/cursors.properties	i386/jvm.cfg
SFILES+=	logging.properties		psfont.properties.ja
SFILES+=	psfontj2d.properties		security/java.security
CONF_FILES=	# empty
.for FILE in ${SFILES}
CONF_FILES+=	${JAVA_HOME}/lib/${FILE}.default ${JAVA_HOME}/lib/${FILE}
.endfor

PKG_OPTIONS_VAR=	PKG_OPTIONS.sun-jre14
PKG_SUPPORTED_OPTIONS=	sun-jre-jce

.include "../../mk/bsd.options.mk"

PLIST_SRC=	${WRKDIR}/PLIST

.if !empty(PKG_OPTIONS:Msun-jre-jce)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} jce_policy-1_4_2.zip
.endif

do-configure:
	cd ${WRKSRC}/lib; for file in ${SFILES}; do			\
		${MV} -f $$file $$file.default;				\
	done

pre-install:
.if !empty(PKG_OPTIONS:Msun-jre-jce)
	cd ${WRKDIR}/jce ; ${PAX} -rw -pe -v . ${WRKSRC}/lib/security
	${SED} 's/@SUN_JRE14_USE_JCE@//' ${PKGDIR}/PLIST > ${PLIST_SRC}
.else
	${SED} '/@SUN_JRE14_USE_JCE@/d' ${PKGDIR}/PLIST > ${PLIST_SRC}
.endif

.include "../../lang/sun-jre14/Makefile.common"
