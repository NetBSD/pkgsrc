# $NetBSD: Makefile,v 1.6 2022/01/10 08:09:06 wiz Exp $

PKGREVISION= 1
.include "../../net/nmap/Makefile.common"

PKGNAME=	${DISTNAME:S/nmap/zenmap/}

COMMENT=	Nmap Security Scanner GUI

WRKSRC=		${WRKDIR}/${DISTNAME}/zenmap

EXTRACT_ELEMENTS=	${DISTNAME}/zenmap

EGG_NAME=	${PKGNAME:C/-([^0-9])/_\1/g}

# There is an ongoing effort of porting Zenmap to Python 3. See
# https://github.com/nmap/nmap/issues/1176
PYTHON_VERSIONS_ACCEPTED=	27

DEPENDS+=	nmap-[0-9]*:../../net/nmap
DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

PYSETUPARGS+=		vanilla

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	pre-configure
SUBST_MESSAGE.setup=	Fixing setup.
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e 's,\(self.create_uninstaller\),\#\1,g'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
