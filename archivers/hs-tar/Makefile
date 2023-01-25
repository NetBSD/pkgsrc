# $NetBSD: Makefile,v 1.9 2023/01/25 09:57:38 pho Exp $

DISTNAME=	tar-0.5.1.1
PKGREVISION=	4
CATEGORIES=	archivers

MAINTAINER=	pho@cielonegro.org
COMMENT=	Reading, writing, and manipulating ".tar" archive files
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	bytestring	\
	directory	\
	time

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
