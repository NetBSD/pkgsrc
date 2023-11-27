# $NetBSD: Makefile,v 1.5 2023/11/27 03:21:00 thorpej Exp $

DISTNAME=	x16-rom-46
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=X16Community/}
GITHUB_PROJECT=	x16-rom
GITHUB_TAG=	r${PKGVERSION_NOREV}

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	http://commanderx16.com/
COMMENT=	ROM for the Commander X16 computer system
LICENSE=	commander-x16-rom-license

TOOL_DEPENDS+=	cc65-[0-9]*:../../cross/cc65
TOOL_DEPENDS+=	lzsa-[0-9]*:../../archivers/lzsa

MAKE_ENV+=	GIT_REV=${GITHUB_TAG}

USE_TOOLS+=	gmake bash

INSTALLATION_DIRS= share/x16

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/x16/rom.bin \
	    ${DESTDIR}${PREFIX}/share/x16

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
