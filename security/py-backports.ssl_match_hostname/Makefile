# $NetBSD: Makefile,v 1.11 2019/04/26 13:14:12 maya Exp $

DISTNAME=	backports.ssl_match_hostname-3.5.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	python security www
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports.ssl_match_hostname/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/backports.ssl_match_hostname
COMMENT=	Python SSL support module for Python 2
LICENSE=	python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-backports-[0-9]*:../../devel/py-backports

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # included in 3.2+

post-install:
	rm ${DESTDIR}${PREFIX}/${PYSITELIB}/backports/__init__.*

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
