# $NetBSD: Makefile,v 1.13 2025/02/02 13:05:28 pho Exp $

DISTNAME=	turtle-1.6.2
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Shell programming, Haskell-style
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring	\
	containers	\
	filepath	\
	text

.include "../../textproc/hs-ansi-wl-pprint/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.include "../../time/hs-clock/buildlink3.mk"
.include "../../devel/hs-foldl/buildlink3.mk"
.include "../../sysutils/hs-hostname/buildlink3.mk"
.include "../../devel/hs-managed/buildlink3.mk"
.include "../../devel/hs-optional-args/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-streaming-commons/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
