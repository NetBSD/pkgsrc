# $NetBSD: Makefile,v 1.21 2015/04/14 11:25:37 wiz Exp $

DISTNAME=	blockdiag-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://pypi.python.org/packages/source/b/blockdiag/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://blockdiag.com/
COMMENT=	Generate block-diagram image file from spec-text file
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Pillow>=2.2.1:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-funcparserlib>=0.3.6:../../devel/py-funcparserlib
DEPENDS+=	${PYPKGPREFIX}-webcolors-[0-9]*:../../www/py-webcolors

PYTHON_SELF_CONFLICT=		yes

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/blockdiag.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
MESSAGE_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
.include "../../mk/bsd.pkg.mk"
