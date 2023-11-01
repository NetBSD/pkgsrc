# $NetBSD: Makefile,v 1.1 2023/11/01 17:17:00 pho Exp $

DISTNAME=	hfsevents-0.1.6
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
