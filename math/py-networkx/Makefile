# $NetBSD: Makefile,v 1.25 2018/02/01 21:00:25 adam Exp $

DISTNAME=	networkx-2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/networkx/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://networkx.github.io/
COMMENT=	Python package for creating and manipulating graphs and networks
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-decorator>=4.1.0:../../devel/py-decorator

USE_LANGUAGES=	# none

post-install:
	${RM} -f -r ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${MV} ${DESTDIR}${PREFIX}/share/doc/${DISTNAME} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
