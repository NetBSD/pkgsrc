# $NetBSD: Makefile,v 1.4 2004/03/26 02:27:47 wiz Exp $
#

.include "../../net/bittorrent/Makefile.common"

PKGNAME=	${DISTNAME:S/BitTorrent/bittorrent-gui/}
PKGREVISION=	2

COMMENT+=	(wxGTK GUI)

DEPENDS+=	bittorrent>=3.4:../../net/bittorrent

NO_BUILD=	# defined

PYTHON_PATCH_SCRIPTS= btcompletedirgui.py btdownloadgui.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/btcompletedirgui.py ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/btdownloadgui.py ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../x11/py-wxWindows/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
