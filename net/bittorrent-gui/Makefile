# $NetBSD: Makefile,v 1.6 2004/04/27 03:43:54 snj Exp $
#

.include "../../net/bittorrent/Makefile.common"

PKGNAME=	${DISTNAME:S/BitTorrent/bittorrent-gui/}

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
