# $NetBSD: Makefile,v 1.4 2024/05/09 01:31:58 pho Exp $

DISTNAME=	hfsevents-0.1.7
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	File/folder watching for OS X
LICENSE=	modified-bsd

# This package is a binding to a Darwin-specific API. It makes no sense on
# any other platforms.
ONLY_FOR_PLATFORM+=	Darwin-*-*

.include "../../devel/hs-cereal/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
