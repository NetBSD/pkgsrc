# $NetBSD: Makefile,v 1.22 2026/06/14 08:35:34 drixter Exp $

DISTNAME=	ShellCheck-0.11.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	shells devel

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://www.shellcheck.net/
COMMENT=	Shell script analysis tool
LICENSE=	gnu-gpl-v3

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	Diff		\
	QuickCheck	\
	aeson		\
	filepath	\
	mtl		\
	transformers

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-fgl/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
