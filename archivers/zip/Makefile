# $NetBSD: Makefile,v 1.48 2005/12/01 16:41:30 rillig Exp $

DISTNAME=	zip231
PKGNAME=	zip-2.31
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.info-zip.org/pub/infozip/src/ \
		http://ftp.info-zip.org/pub/infozip/src/ \
		http://sunsite.cnlab-switch.ch/ftp/mirror/infozip/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/infozip/src/ \
		http://www.mirrorservice.org/sites/ftp.info-zip.org/pub/infozip/src/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.info-zip.org/pub/infozip/Zip.html
COMMENT=	Create/update ZIP files compatible with pkzip

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKEFILE=	unix/Makefile
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/bsd.prefs.mk"

MAKE_FLAGS+=	LOCAL_ZIP=${CFLAGS:M*:Q}
MAKE_FLAGS+=	LFLAGS1=${_STRIPFLAG_CC:Q}
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "powerpc"
CFLAGS+=	-O0
.endif

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc*)
BUILD_TARGET=	generic_gcc
.else
BUILD_TARGET=	generic
CFLAGS+=	-O
.endif

.if ${OPSYS} == "Linux"
CFLAGS+=	-DHAVE_DIRENT_H
.endif

INSTALLATION_DIRS=	bin man/man1

do-install:
	cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM} zip zipnote zipsplit zipcloak ${PREFIX}/bin
	cd ${WRKSRC}/man && \
	    ${INSTALL_MAN} zip.1 ${PREFIX}/man/man1
	${LN} -f -s zip.1 ${PREFIX}/man/man1/zipcloak.1
	${LN} -f -s zip.1 ${PREFIX}/man/man1/zipnote.1
	${LN} -f -s zip.1 ${PREFIX}/man/man1/zipsplit.1

.include "../../mk/bsd.pkg.mk"
