# $NetBSD: Makefile,v 1.10 2005/06/17 03:50:24 jlam Exp $
#

.include "../../net/bittorrent/Makefile.common"

PKGNAME=	${DISTNAME:S/BitTorrent/bittorrent-gui/}

COMMENT+=	(GTK+ GUI)

DEPENDS+=	bittorrent>=4.0.1:../../net/bittorrent

PYTHON_PATCH_SCRIPTS= btdownloadgui.py btmaketorrentgui.py

INSTALLATION_DIRS=	bin

do-build:	# empty

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/btdownloadgui.py ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/btmaketorrentgui.py ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
