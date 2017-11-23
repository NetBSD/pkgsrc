# $NetBSD: Makefile,v 1.35 2017/11/23 17:20:14 wiz Exp $

PKGREVISION= 5
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.5.4
DISTNAME=	xarchiver-${VERSION}
PKGNAME=	xfce4-xarchiver-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xarchiver/}

HOMEPAGE=	http://xarchiver.sourceforge.net/
COMMENT=	Xfce archiver handler

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
