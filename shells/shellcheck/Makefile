# $NetBSD: Makefile,v 1.1 2020/10/13 11:16:19 jperkin Exp $

DISTNAME=	ShellCheck-0.7.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	shells devel

MAINTAINER=	pkgsrc-users@pkgsrc.org
COMMENT=	Shell script analysis tool
LICENSE=	gnu-gpl-v3

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
