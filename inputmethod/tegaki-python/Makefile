# $NetBSD: Makefile,v 1.18 2022/06/30 11:18:31 nia Exp $

DISTNAME=	tegaki-python-0.3.1
PKGREVISION=	5
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

PYTHON_VERSIONS_ACCEPTED=	27 # py-zinnia

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
