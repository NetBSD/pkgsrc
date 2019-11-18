# $NetBSD: Makefile,v 1.25 2019/11/18 04:41:34 gutteridge Exp $

DISTNAME=	blockdiag-1.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blockdiag/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://blockdiag.com/
COMMENT=	Generate block-diagram image file from spec-text file
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-funcparserlib>=0.3.6:../../devel/py-funcparserlib
DEPENDS+=	${PYPKGPREFIX}-reportlab-[0-9]*:../../print/py-reportlab
DEPENDS+=	${PYPKGPREFIX}-webcolors-[0-9]*:../../www/py-webcolors
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-pep8>=1.3:../../devel/py-pep8
TEST_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	cd ${DESTDIR}${PREFIX} && \
		${MV} bin/blockdiag bin/blockdiag-${PYVERSSUFFIX} || ${TRUE}
	${INSTALL_MAN} ${WRKSRC}/blockdiag.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/blockdiag-${PYVERSSUFFIX}.1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
