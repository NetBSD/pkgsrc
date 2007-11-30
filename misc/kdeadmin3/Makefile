# $NetBSD: Makefile,v 1.41 2007/11/30 21:55:08 wiz Exp $

DISTNAME=	kdeadmin-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	System administration tools for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-shadow
.else
CONFIGURE_ARGS+=	--without-shadow
.endif
CONFIGURE_ENV+=		DO_NOT_COMPILE=ksysv

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
