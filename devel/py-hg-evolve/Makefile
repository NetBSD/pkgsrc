# $NetBSD: Makefile,v 1.9 2020/05/04 17:23:28 riastradh Exp $

DISTNAME=	hg-evolve-9.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hg-evolve/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://www.mercurial-scm.org/doc/evolution/
COMMENT=	Experimental Mercurial extensions from Facebook
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mercurial>=4.3.1:../../devel/py-mercurial
DEPENDS+=	${PYPKGPREFIX}-sqlite3>=0:../../databases/py-sqlite3

post-install:
	rm -f ${DESTDIR}${PREFIX}/${PYSITELIB}/hgext3rd/__init__.py*
	rm -f ${DESTDIR}${PREFIX}/${PYSITELIB}/hgext3rd/__pycache__/__init__.*

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
