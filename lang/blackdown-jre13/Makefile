# $NetBSD: Makefile,v 1.11 2003/08/02 19:26:29 kristerw Exp $
#

BASENAME=	j2re
DISTNAME=	${EXTNAME}-${BLACKDOWN_ARCH}
PKGNAME=	blackdown-jre13-1
PKGREVISION=	1
COMMENT=	Blackdown's Java(tm) Runtime Environment 1.3.1

.if ${MACHINE_ARCH} == "arm"
DISTNAME=	${BASENAME}-${RELVERSION}-RC1-linux-arm
.endif

.include "../../lang/blackdown-jre13/Makefile.common"

ONLY_FOR_PLATFORM+=	NetBSD-*-arm Linux-*-arm

PLIST_SRC=	${PKGDIR}/PLIST
.if ${BLACKDOWN_ARCH} == "i386"
PLIST_SRC+=	${PKGDIR}/PLIST.i386
.endif

USE_PKGINSTALL=	yes
OWN_DIRS=	${PREFIX}
OWN_DIRS+=	${PREFIX}/lib
OWN_DIRS+=	${PREFIX}/lib/${BLACKDOWN_ARCH}
OWN_DIRS+=	${PREFIX}/lib/applet
OWN_DIRS+=	${PREFIX}/lib/ext
OWN_DIRS+=	${PREFIX}/lib/images
OWN_DIRS+=	${PREFIX}/lib/images/cursors
OWN_DIRS+=	${PREFIX}/lib/security
OWN_DIRS+=	${PREFIX}/plugin/${BLACKDOWN_ARCH}
OWN_DIRS+=	${PREFIX}/plugin
SFILES=		content-types.properties	flavormap.properties
SFILES+=	font.properties			font.properties.ja
SFILES+=	font.properties.zh		jvm.cfg
SFILES+=	images/cursors/cursors.properties	psfont.properties.ja
SFILES+=	psfontj2d.properties		security/java.security
SUPPORT_FILES=	# empty
.for FILE in ${SFILES}
SUPPORT_FILES+=	${PREFIX}/lib/${FILE}.default ${PREFIX}/lib/${FILE}
.endfor

do-configure:
	cd ${WRKSRC}/lib; for file in ${SFILES}; do			\
		${MV} -f $$file $$file.default;				\
	done

.include "../../mk/bsd.pkg.mk"

PREFIX=		${JVM_HOME}
