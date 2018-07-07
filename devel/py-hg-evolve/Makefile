# $NetBSD: Makefile,v 1.2 2018/07/07 21:17:02 joerg Exp $

DISTNAME=	hg-evolve-8.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hg-evolve/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://www.mercurial-scm.org/doc/evolution/
COMMENT=	Experimental Mercurial extensions from Facebook
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mercurial>=4.3.1:../../devel/py-mercurial

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # See Mercurial itself.
PYDISTUTILSPKG=	YES

post-install:
	rm -f ${DESTDIR}${PREFIX}/${PYSITELIB}/hgext3rd/__init__.py*

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
