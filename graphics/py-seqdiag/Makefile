# $NetBSD: Makefile,v 1.21 2022/01/05 15:41:12 wiz Exp $

DISTNAME=	seqdiag-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/seqdiag/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://blockdiag.com/
COMMENT=	Simple sequence-diagram image generator
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-blockdiag>=1.5.0:../../graphics/py-blockdiag

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} seqdiag seqdiag-${PYVERSSUFFIX} || ${TRUE}
	${INSTALL_MAN} ${WRKSRC}/seqdiag.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/seqdiag-${PYVERSSUFFIX}.1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
