# $NetBSD: Makefile,v 1.4 2024/05/09 01:31:39 pho Exp $

DISTNAME=	criterion-measurement-0.2.1.0
PKGREVISION=	2
CATEGORIES=	benchmarks

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Criterion measurement functionality and associated types
LICENSE=	modified-bsd

# See cbits/cycles.c
BROKEN_EXCEPT_ON_PLATFORM+=	*-*-aarch64
BROKEN_EXCEPT_ON_PLATFORM+=	*-*-i386
BROKEN_EXCEPT_ON_PLATFORM+=	*-*-x86_64
BROKEN_EXCEPT_ON_PLATFORM+=	Darwin-*-*
BROKEN_EXCEPT_ON_PLATFORM+=	Linux-*-*

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
