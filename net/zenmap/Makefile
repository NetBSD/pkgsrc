# $NetBSD: Makefile,v 1.11 2023/06/06 10:45:10 adam Exp $

.include "../../net/nmap/Makefile.common"

PKGNAME=	${DISTNAME:S/nmap/zenmap/}

COMMENT=	Nmap Security Scanner GUI

WRKSRC=		${WRKDIR}/${DISTNAME}/zenmap

EXTRACT_ELEMENTS=	${DISTNAME}/zenmap

EGG_NAME=	zenmap-${PKGVERSION_NOREV}

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	gtk3+-[0-9]*:../../x11/gtk3
DEPENDS+=	nmap-[0-9]*:../../net/nmap
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

PYSETUPARGS+=		vanilla

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	pre-configure
SUBST_MESSAGE.setup=	Fixing setup.
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e 's,\(self.create_uninstaller\),\#\1,g'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
