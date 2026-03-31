# $NetBSD: Makefile,v 1.48 2026/03/31 13:10:49 adam Exp $

DISTNAME=	pygit2-1.19.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygit2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libgit2/pygit2
COMMENT=	Python bindings to libgit2
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=2.0:../../devel/py-cffi
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=	c99

BUILDLINK_API_DEPENDS.libgit2+=	libgit2>=1.9
.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
