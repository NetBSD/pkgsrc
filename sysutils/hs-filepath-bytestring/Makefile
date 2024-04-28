# $NetBSD: Makefile,v 1.3 2024/04/28 11:48:16 pho Exp $

# NOTE: We can't update this to >=1.5.2 because it requires GHC newer than
# 9.8.
DISTNAME=	filepath-bytestring-1.4.2.1.13
PKGREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library for manipulating RawFilePaths in a cross platform way
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
