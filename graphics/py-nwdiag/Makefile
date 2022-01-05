# $NetBSD: Makefile,v 1.18 2022/01/05 15:41:11 wiz Exp $

DISTNAME=	nwdiag-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nwdiag/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://blockdiag.com/
COMMENT=	Simple network-diagram image generator
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-blockdiag>=1.5.0:../../graphics/py-blockdiag

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in nwdiag packetdiag rackdiag
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
	${INSTALL_MAN} ${WRKSRC}/${bin}.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${bin}-${PYVERSSUFFIX}.1
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
