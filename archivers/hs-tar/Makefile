# $NetBSD: Makefile,v 1.12 2023/11/02 06:36:10 pho Exp $

DISTNAME=	tar-0.5.1.1
PKGREVISION=	7
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
