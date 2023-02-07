# $NetBSD: Makefile,v 1.7 2023/02/07 01:40:41 pho Exp $

DISTNAME=	implicit-hie-cradle-0.5.0.0
PKGREVISION=	5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Auto generate hie-bios cradles
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring	\
	text	\
	time	\
	unix-compat	\
	vector

.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-hie-bios/buildlink3.mk"
.include "../../sysutils/hs-hslogger/buildlink3.mk"
.include "../../devel/hs-implicit-hie/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
