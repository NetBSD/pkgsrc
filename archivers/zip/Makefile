# $NetBSD: Makefile,v 1.42 2005/03/24 21:12:50 wiz Exp $

DISTNAME=	zip-2.3
PKGREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.info-zip.org/pub/infozip/src/
DISTFILES=	zip23.tar.gz zcrypt29.zip

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.info-zip.org/pub/infozip/Zip.html
COMMENT=	Create/update ZIP files compatible with pkzip

BUILD_DEPENDS=	unzip-[0-9]*:../../archivers/unzip

PKG_INSTALLATION_TYPES=	overwrite pkgviews

EXTRACT_ONLY=	zip23.tar.gz
MAKEFILE=	unix/Makefile
MAKE_FLAGS=	LOCAL_ZIP="${CFLAGS}" LFLAGS1="${_STRIPFLAG_CC}"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "powerpc"
CFLAGS=		-O0
.endif

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc*)
BUILD_TARGET=	generic_gcc
.else
BUILD_TARGET=	generic
CFLAGS=		-O
.endif

.if ${OPSYS} == "Linux"
CFLAGS+=	-DHAVE_DIRENT_H
.endif

USE_BUILDLINK3=	yes

INSTALLATION_DIRS=	bin man/man1

post-extract:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/unzip -qo ${DISTDIR}/zcrypt29.zip

do-install:
	cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM} zip zipnote zipsplit zipcloak ${PREFIX}/bin
	cd ${WRKSRC}/man && \
	    ${INSTALL_MAN} zip.1 ${PREFIX}/man/man1
	${LN} -f -s zip.1 ${PREFIX}/man/man1/zipcloak.1
	${LN} -f -s zip.1 ${PREFIX}/man/man1/zipnote.1
	${LN} -f -s zip.1 ${PREFIX}/man/man1/zipsplit.1

.include "../../mk/bsd.pkg.mk"
