# $NetBSD: Makefile,v 1.1 2018/05/21 16:23:04 minskim Exp $

DISTNAME=	aslc86k
PKGNAME=	aslc86k-1.9
CATEGORIES=	devel
MASTER_SITES=	http://mc.pp.se/dc/files/

MAINTAINER=	tr@vispaul.me
HOMEPAGE=	http://mc.pp.se/dc/files/
COMMENT=	Macro assembler that can assemble programs of the Visual Memory System
LICENSE=	mit

WRKSRC=			${WRKDIR}/as
USE_TOOLS+=		gmake
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aslc86k ${DESTDIR}${PREFIX}/bin/aslc86k

.include "../../mk/bsd.pkg.mk"
