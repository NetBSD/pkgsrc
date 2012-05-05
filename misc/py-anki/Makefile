# $NetBSD: Makefile,v 1.1.1.1 2012/05/05 22:22:51 wiz Exp $

.include "Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

DEPENDS+=	${PYPKGPREFIX}-qt4>=4.4:../../x11/py-qt4
DEPENDS+=	${PYPKGPREFIX}-libanki-[0-9]*:../../misc/py-libanki

REPLACE_PYTHON=		anki ankiqt/ui/dropbox.py
EGG_NAME=		${DISTNAME:S/anki/ankiqt/}
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/anki ${DESTDIR}${PREFIX}/bin/anki${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
