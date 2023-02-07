# $NetBSD: Makefile,v 1.11 2023/02/07 01:41:05 pho Exp $

DISTNAME=	ShellCheck-0.9.0
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	shells devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.shellcheck.net/
COMMENT=	Shell script analysis tool
LICENSE=	gnu-gpl-v3

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-fgl/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
