# $NetBSD: Makefile,v 1.5 2004/03/29 23:39:43 wiz Exp $
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
.include "../../x11/py-wxWindows/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
