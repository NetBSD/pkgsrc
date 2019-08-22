# $NetBSD: Makefile,v 1.32 2019/08/22 12:23:36 ryoon Exp $

DISTNAME=	juk-${_KDE_VERSION}
PKGREVISION=	15
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
