# $NetBSD: Makefile,v 1.16 2022/01/10 20:27:16 wiz Exp $

DISTNAME=	backports.ssl_match_hostname-3.7.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python www
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports.ssl_match_hostname/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/brandon/backports.ssl_match_hostname
COMMENT=	Python SSL support module for Python 2
LICENSE=	python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-backports-[0-9]*:../../devel/py-backports

PYTHON_VERSIONS_ACCEPTED=	27 # included in 3.2+

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/backports/__init__.*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
