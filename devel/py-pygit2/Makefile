# $NetBSD: Makefile,v 1.3 2018/06/05 18:48:52 wiz Exp $

DISTNAME=	pygit2-0.27.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygit2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libgit2/pygit2
COMMENT=	Python bindings to libgit2
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.libgit2+=	libgit2>=0.27.0
.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
