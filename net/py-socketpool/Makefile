# $NetBSD: Makefile,v 1.8 2017/01/01 14:43:52 wiz Exp $

DISTNAME=	socketpool-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=s/socketpool/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/benoitc/socketpool
COMMENT=	Simple Python socket pool
LICENSE=	unlicense OR mit

USE_LANGUAGES=	# none

DOCDIR=			share/doc/${PKGBASE:S/${PYPKGPREFIX}/py/1}
INSTALLATION_DIRS+=	${DOCDIR}

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.5.3

post-install:
	${INSTALL_DATA} ${DESTDIR}${PREFIX}/socketpool/README.rst \
		${DESTDIR}${PREFIX}/${DOCDIR}
	${RM} -rf ${DESTDIR}${PREFIX}/socketpool

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
