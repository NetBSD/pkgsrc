# $NetBSD: Makefile,v 1.11 2023/10/09 04:54:02 pho Exp $

DISTNAME=	tar-0.5.1.1
PKGREVISION=	6
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
