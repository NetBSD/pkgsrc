# $NetBSD: Makefile,v 1.13 2005/05/15 11:53:20 veego Exp $
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

USE_PKGINSTALL=	yes
OWN_DIRS=	${JVM_HOME}
OWN_DIRS+=	${JVM_HOME}/lib
OWN_DIRS+=	${JVM_HOME}/lib/${BLACKDOWN_ARCH}
OWN_DIRS+=	${JVM_HOME}/lib/applet
OWN_DIRS+=	${JVM_HOME}/lib/ext
OWN_DIRS+=	${JVM_HOME}/lib/images
OWN_DIRS+=	${JVM_HOME}/lib/images/cursors
OWN_DIRS+=	${JVM_HOME}/lib/security
OWN_DIRS+=	${JVM_HOME}/plugin/${BLACKDOWN_ARCH}
OWN_DIRS+=	${JVM_HOME}/plugin
SFILES=		content-types.properties	flavormap.properties
SFILES+=	font.properties			font.properties.ja
SFILES+=	font.properties.zh		jvm.cfg
SFILES+=	images/cursors/cursors.properties	psfont.properties.ja
SFILES+=	psfontj2d.properties		security/java.security
SUPPORT_FILES=	# empty
.for FILE in ${SFILES}
SUPPORT_FILES+=	${JVM_HOME}/lib/${FILE}.default ${JVM_HOME}/lib/${FILE}
.endfor

do-configure:
	cd ${WRKSRC}/lib; for file in ${SFILES}; do			\
		${MV} -f $$file $$file.default;				\
	done

.include "../../mk/bsd.pkg.mk"
