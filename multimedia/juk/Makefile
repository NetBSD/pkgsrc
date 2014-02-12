# $NetBSD: Makefile,v 1.12 2014/02/12 23:18:17 tron Exp $

DISTNAME=	juk-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	multimedia
COMMENT=	a jukebox, tagger and music collection manager.

post-patch:
	cp ${WRKSRC}/tag.h ${WRKSRC}/tagxx.h

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../audio/libtunepimp/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
