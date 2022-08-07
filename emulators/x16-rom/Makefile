# $NetBSD: Makefile,v 1.3 2022/08/07 17:36:52 thorpej Exp $

DISTNAME=	x16-rom-41
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=commanderx16/}
GITHUB_PROJECT=	x16-rom
GITHUB_TAG=	r${PKGVERSION_NOREV}

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	http://commanderx16.com/
COMMENT=	ROM for the Commander X16 computer system
LICENSE=	commander-x16-rom-license

TOOL_DEPENDS+=	cc65-[0-9]*:../../cross/cc65

USE_TOOLS+=	gmake bash

INSTALLATION_DIRS= share/x16

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/x16/rom.bin \
	    ${DESTDIR}${PREFIX}/share/x16

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
