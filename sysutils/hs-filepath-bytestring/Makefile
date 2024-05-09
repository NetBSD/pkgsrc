# $NetBSD: Makefile,v 1.4 2024/05/09 01:32:36 pho Exp $

# NOTE: We can't update this to >=1.5.2 because it requires GHC newer than
# 9.8.
DISTNAME=	filepath-bytestring-1.4.2.1.13
PKGREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library for manipulating RawFilePaths in a cross platform way
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
