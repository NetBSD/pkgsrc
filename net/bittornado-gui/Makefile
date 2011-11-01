# $NetBSD: Makefile,v 1.26 2011/11/01 11:13:40 obache Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../net/bittornado/Makefile.common"

PKGNAME=	${DISTNAME:S/Tornado/Tornado-gui/}
PKGREVISION=	10

COMMENT+=	(wxGTK GUI)

CONFLICTS=	bittorrent-gui-[0-9]*

DEPENDS+=	BitTornado>=0.3.18:../../net/bittornado
DEPENDS+=	${PYPKGPREFIX}-wxWidgets-[0-9]*:../../x11/py-wxWidgets

NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	btcompletedirgui.py btdownloadgui.py
PYTHON_PATCH_SCRIPTS+=	btmaketorrentgui.py

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/btcompletedirgui.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/btdownloadgui.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/btmaketorrentgui.py ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
