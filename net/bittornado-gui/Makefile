# $NetBSD: Makefile,v 1.23 2011/01/13 13:39:01 wiz Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../net/bittornado/Makefile.common"

PKGNAME=	${DISTNAME:S/Tornado/Tornado-gui/}
PKGREVISION=	8

COMMENT+=	(wxGTK GUI)

CONFLICTS=	bittorrent-gui-[0-9]*

DEPENDS+=	BitTornado>=0.3.18:../../net/bittornado

NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	btcompletedirgui.py btdownloadgui.py
PYTHON_PATCH_SCRIPTS+=	btmaketorrentgui.py

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/btcompletedirgui.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/btdownloadgui.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/btmaketorrentgui.py ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
