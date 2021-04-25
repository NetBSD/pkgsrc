# $NetBSD: Makefile,v 1.1 2021/04/25 04:14:51 pho Exp $

DISTNAME=	hslua-module-path-0.1.0.1
CATEGORIES=	sysutils

MAINTAINER=	pho@cielonegro.org
COMMENT=	Lua module to work with file paths
LICENSE=	mit

# Setup.hs is missing from the package.
post-patch:
	${CP} -f ${FILESDIR}/Setup.hs ${WRKSRC}/Setup.hs

.include "../../lang/hs-hslua/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
