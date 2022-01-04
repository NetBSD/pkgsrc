#	$NetBSD: Makefile,v 1.2 2022/01/04 20:52:46 wiz Exp $

DISTNAME=	CppHeaderParser-2.7.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=C/CppHeaderParser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://senexcanis.com/open-source/cppheaderparser/
COMMENT=	Python library to parse C++ header files
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-ply>=0:../../devel/py-ply

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	CppHeaderParser/examples/readSampleClass.py

do-test:
	${RUN} cd ${WRKSRC}/CppHeaderParser/examples && \
	${PYTHONBIN} ./readSampleClass.py >/dev/null

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
