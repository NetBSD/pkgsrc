# $NetBSD: Makefile,v 1.2 2019/12/31 10:23:37 mef Exp $

DISTNAME=	x16-rom-35
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=commanderx16/}
GITHUB_PROJECT=	x16-rom
GITHUB_TAG=	r${PKGVERSION_NOREV}

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	http://commanderx16.com/
COMMENT=	ROM for the Commander X16 computer system
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	cc65-[0-9]*:../../cross/cc65

USE_TOOLS+=	gmake bash

INSTALLATION_DIRS= share/x16

do-install:
	${INSTALL_DATA} ${WRKSRC}/rom.bin ${DESTDIR}${PREFIX}/share/x16

.include "../../mk/bsd.pkg.mk"
