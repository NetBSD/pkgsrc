# $NetBSD: Makefile,v 1.13 2013/12/06 11:26:55 obache Exp $
#

DISTNAME=	blockdiag-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://pypi.python.org/packages/source/b/blockdiag/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://blockdiag.com/
COMMENT=	Generate block-diagram image file from spec-text file
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-Pillow>=2.2.1:../../graphics/Pillow
DEPENDS+=	${PYPKGPREFIX}-funcparserlib>=0.3.6:../../devel/py-funcparserlib
DEPENDS+=	${PYPKGPREFIX}-webcolors-[0-9]*:../../www/py-webcolors

PYTHON_SELF_CONFLICT=		yes
PYTHON_VERSIONS_INCLUDE_3X=	yes

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/blockdiag.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.if ${PYPKGPREFIX} == "py26"
DEPENDS+=	${PYPKGPREFIX}-ordereddict-[0-9]*:../../devel/py-ordereddict
.endif
MESSAGE_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
.include "../../mk/bsd.pkg.mk"
