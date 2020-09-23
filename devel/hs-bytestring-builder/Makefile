# $NetBSD: Makefile,v 1.2 2020/09/23 21:34:45 mef Exp $

DISTNAME=	bytestring-builder-0.10.8.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=bytestring-builder-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hackage.haskell.org/package/bytestring-builder
COMMENT=	The new bytestring builder, packaged outside of GHC
LICENSE=	modified-bsd

PLIST_SUBST=	HASKELL_VERSION=${_HASKELL_VERSION:Q}

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
