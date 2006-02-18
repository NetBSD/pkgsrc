# $NetBSD: Makefile,v 1.16 2006/02/18 22:13:23 wiz Exp $
#

BD_BASENAME=	j2re
DISTNAME=	${EXTNAME}-${BLACKDOWN_ARCH}
PKGNAME=	blackdown-jre13-1
PKGREVISION=	2
COMMENT=	Blackdown's Java(tm) Runtime Environment 1.3.1

.if ${MACHINE_ARCH} == "arm"
DISTNAME=	${BD_BASENAME}-${RELVERSION}-RC1-linux-arm
.endif

.include "../../lang/blackdown-jre13/Makefile.common"

ONLY_FOR_PLATFORM+=	NetBSD-*-arm Linux-*-arm

PLIST_SRC=	${PKGDIR}/PLIST
.if ${BLACKDOWN_ARCH} == "i386"
PLIST_SRC+=	${PKGDIR}/PLIST.i386
.endif

REQD_DIRS=	${JVM_HOME}
REQD_DIRS+=	${JVM_HOME}/lib
REQD_DIRS+=	${JVM_HOME}/lib/${BLACKDOWN_ARCH}
REQD_DIRS+=	${JVM_HOME}/lib/applet
REQD_DIRS+=	${JVM_HOME}/lib/ext
REQD_DIRS+=	${JVM_HOME}/lib/images
REQD_DIRS+=	${JVM_HOME}/lib/images/cursors
REQD_DIRS+=	${JVM_HOME}/lib/security
REQD_DIRS+=	${JVM_HOME}/plugin/${BLACKDOWN_ARCH}
REQD_DIRS+=	${JVM_HOME}/plugin
SFILES=		content-types.properties	flavormap.properties
SFILES+=	font.properties			font.properties.ja
SFILES+=	font.properties.zh		jvm.cfg
SFILES+=	images/cursors/cursors.properties	psfont.properties.ja
SFILES+=	psfontj2d.properties		security/java.security
CONF_FILES=	# empty
.for file in ${SFILES}
CONF_FILES+=	${JVM_HOME}/lib/${file}.default ${JVM_HOME}/lib/${file}
.endfor

do-configure:
	cd ${WRKSRC}/lib; for file in ${SFILES}; do			\
		${MV} -f $$file $$file.default;				\
	done

.include "../../mk/bsd.pkg.mk"
