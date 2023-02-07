# $NetBSD: Makefile,v 1.10 2023/02/07 01:40:22 pho Exp $

DISTNAME=	tar-0.5.1.1
PKGREVISION=	5
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
