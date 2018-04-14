# $NetBSD: Makefile,v 1.1 2018/04/14 13:04:33 adam Exp $

.include "../../net/nmap/Makefile.common"

PKGNAME=	${DISTNAME:S/nmap/zenmap/}

COMMENT=	Nmap Security Scanner GUI

WRKSRC=		${WRKDIR}/${DISTNAME}/zenmap

EXTRACT_ELEMENTS=	${DISTNAME}/zenmap

PYTHON_VERSIONS_ACCEPTED=	27

DEPENDS+=	nmap-[0-9]*:../../net/nmap
DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

PYSETUPARGS+=		vanilla

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	post-patch
SUBST_MESSAGE.setup=	Fixing setup.
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e 's,\(self.create_uninstaller\),\#\1,g'

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
