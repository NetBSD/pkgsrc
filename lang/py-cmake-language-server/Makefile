# $NetBSD: Makefile,v 1.2 2020/05/19 05:14:01 wiz Exp $

DISTNAME=	cmake-language-server-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmake-language-server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/regen100/cmake-language-server
COMMENT=	CMake Language Server Protocol Implementation
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pygls-[0-9]*:../../lang/py-pygls
DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-pygls

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} cmake-format cmake-format-${PYVERSSUFFIX}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} cmake-language-server cmake-language-server-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
