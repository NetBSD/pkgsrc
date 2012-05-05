# $NetBSD: Makefile,v 1.1.1.1 2012/05/05 22:22:15 wiz Exp $

.include "../../wip/py-anki/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/anki/libanki/}
COMMENT=	Flashcard learning program (support libraries)
LICENSE=	gnu-gpl-v3 OR modified-bsd

DEPENDS+=	${PYPKGPREFIX}-simplejson>=1.7.3:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.4.3:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sqlite2>=1.3:../../databases/py-sqlite2
DEPENDS+=	${PYPKGPREFIX}-qt4>=4.4:../../x11/py-qt4
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

PYSETUPSUBDIR=	libanki

.include "../../mk/bsd.pkg.mk"
