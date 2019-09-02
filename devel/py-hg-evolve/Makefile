# $NetBSD: Makefile,v 1.7 2019/09/02 13:19:38 adam Exp $

DISTNAME=	hg-evolve-8.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hg-evolve/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://www.mercurial-scm.org/doc/evolution/
COMMENT=	Experimental Mercurial extensions from Facebook
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mercurial>=4.3.1:../../devel/py-mercurial

PYTHON_VERSIONS_ACCEPTED=	 27 # See Mercurial itself.

post-install:
	rm -f ${DESTDIR}${PREFIX}/${PYSITELIB}/hgext3rd/__init__.py*

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
