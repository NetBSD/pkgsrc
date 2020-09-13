# $NetBSD: Makefile,v 1.13 2020/09/13 11:05:01 wiz Exp $

DISTNAME=	hg-evolve-10.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hg-evolve/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://www.mercurial-scm.org/doc/evolution/
COMMENT=	Experimental Mercurial extensions from Facebook
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mercurial>=5.4nb1:../../devel/py-mercurial
DEPENDS+=	${PYPKGPREFIX}-sqlite3>=0:../../databases/py-sqlite3

post-install:
	rm -f ${DESTDIR}${PREFIX}/${PYSITELIB}/hgext3rd/__init__.py*
	rm -f ${DESTDIR}${PREFIX}/${PYSITELIB}/hgext3rd/__pycache__/__init__.*

.if 0
HG_WRKSRC=	cd ../py-mercurial && ${MAKE} show-var VARNAME=WRKSRC

do-test:
	HGROOT=${HG_WRKSRC:sh}; cd ${WRKSRC}/tests && ${PYTHONBIN} $${HGROOT}/tests/run-tests.py ${_MAKE_JOBS:Q}
.endif

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
