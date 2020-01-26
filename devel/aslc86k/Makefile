# $NetBSD: Makefile,v 1.3 2020/01/26 17:30:55 rillig Exp $

DISTNAME=	aslc86k
PKGNAME=	aslc86k-1.9
CATEGORIES=	devel
MASTER_SITES=	http://mc.pp.se/dc/files/

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://mc.pp.se/dc/files/
COMMENT=	Macro assembler that can assemble programs of the Visual Memory System
LICENSE=	mit

WRKSRC=			${WRKDIR}/as
USE_TOOLS+=		gmake
DIST_SUBDIR=		${PKGNAME_NOREV}
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aslc86k ${DESTDIR}${PREFIX}/bin/aslc86k

.include "../../mk/bsd.pkg.mk"
