# $NetBSD: Makefile,v 1.5 2019/06/08 10:53:29 rillig Exp $
#
# The upstream distfile is unversioned and replaced every time a new version
# is released, so we must put a copy of it up in LOCAL_PORTS with DIST_SUBDIR
# set and download from there.
#

DISTNAME=	objconv
PKGNAME=	${DISTNAME}-2.39
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_LOCAL:=${PKGNAME_NOREV}/}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.agner.org/optimize/
COMMENT=	Object file converter and disassembler
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	unzip:build

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c++

INSTALLATION_DIRS+=	bin

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
BROKEN=		"Does not support big endian systems"
.endif

post-extract:
	cd ${WRKSRC} && unzip source.zip

do-build:
	cd ${WRKSRC} && sh ./build.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/objconv \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
