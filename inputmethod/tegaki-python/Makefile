# $NetBSD: Makefile,v 1.13 2019/04/26 13:14:02 maya Exp $

DISTNAME=	tegaki-python-0.3.1
PKGREVISION=	2
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Base Python library for the Tegaki project
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
# optional for desktop applications, see tegaki/character.py
#DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-zinnia>=0.05:../../inputmethod/py-zinnia

USE_LANGUAGES=	# none

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	tegaki/engine.py
SUBST_SED.prefix=	-e 's|/usr/local/share|${PREFIX}/share|g'

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-zinnia

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
