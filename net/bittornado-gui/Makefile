# $NetBSD: Makefile,v 1.4 2005/01/28 16:19:17 veego Exp $
#

.include "../../net/bittornado/Makefile.common"

PKGNAME=	${DISTNAME:S/Tornado/Tornado-gui/}

COMMENT+=	(wxGTK GUI)

CONFLICTS=	bittorrent-gui-[0-9]*

DEPENDS+=	BitTornado>=0.3.10:../../net/bittornado

NO_BUILD=	# defined

PYTHON_PATCH_SCRIPTS=	btcompletedirgui.py btdownloadgui.py
PYTHON_PATCH_SCRIPTS+=	btmaketorrentgui.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/btcompletedirgui.py ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/btdownloadgui.py ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/btmaketorrentgui.py ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
