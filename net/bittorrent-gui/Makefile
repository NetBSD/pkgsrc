# $NetBSD: Makefile,v 1.7 2004/10/03 00:17:49 tv Exp $
#

.include "../../net/bittorrent/Makefile.common"

PKGNAME=	${DISTNAME:S/BitTorrent/bittorrent-gui/}
PKGREVISION=	1

COMMENT+=	(wxGTK GUI)

DEPENDS+=	bittorrent>=3.4:../../net/bittorrent

NO_BUILD=	# defined

PYTHON_PATCH_SCRIPTS= btcompletedirgui.py btdownloadgui.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/btcompletedirgui.py ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/btdownloadgui.py ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../x11/py-wxWindows/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
