# $NetBSD: Makefile,v 1.10 2019/11/03 10:18:27 rillig Exp $

DISTNAME=	python-gflags-3.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-gflags/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/python-gflags
COMMENT=	Python equivalent of gflags, a commandline flag implementation
LICENSE=	modified-bsd

REPLACE_PYTHON+=	*.py
PYDISTUTILSPKG=		yes

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/gflags2man.py ${DESTDIR}${PREFIX}/bin/gflags2man${PYVERSSUFFIX}.py 
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/gflags2man${PYVERSSUFFIX}.py 

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
