# $NetBSD: Makefile,v 1.3 2014/01/25 10:30:17 wiz Exp $

DISTNAME=	socketpool-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	https://pypi.python.org/packages/source/s/socketpool/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/benoitc/socketpool
COMMENT=	Simple Python socket pool
LICENSE=	unlicense OR mit

USE_LANGUAGES=	# none

DOCDIR=			share/doc/${PKGBASE:S/${PYPKGPREFIX}/py/1}
INSTALLATION_DIRS+=	${DOCDIR}

PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.5.3

post-install:
	${INSTALL_DATA} ${DESTDIR}${PREFIX}/socketpool/README.rst \
		${DESTDIR}${PREFIX}/${DOCDIR}
	${RM} -rf ${DESTDIR}${PREFIX}/socketpool

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
