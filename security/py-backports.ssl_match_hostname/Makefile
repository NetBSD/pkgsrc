# $NetBSD: Makefile,v 1.14 2019/11/28 13:47:00 adam Exp $

DISTNAME=	backports.ssl_match_hostname-3.7.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security www
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports.ssl_match_hostname/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bitbucket.org/brandon/backports.ssl_match_hostname
COMMENT=	Python SSL support module for Python 2
LICENSE=	python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-backports-[0-9]*:../../devel/py-backports

PYTHON_VERSIONS_ACCEPTED=	27 # included in 3.2+

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/backports/__init__.*

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
