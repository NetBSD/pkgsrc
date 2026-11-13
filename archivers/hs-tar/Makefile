# $NetBSD: Makefile,v 1.21 2026/11/13 14:38:39 pho Exp $

DISTNAME=	tar-0.6.4.0
PKGREVISION=	5
CATEGORIES=	archivers

MAINTAINER=	pho@cielonegro.org
COMMENT=	Reading, writing, and manipulating ".tar" archive files
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	file-io

.include "../../sysutils/hs-directory-ospath-streaming/buildlink3.mk"
.include "../../devel/hs-file-io/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
