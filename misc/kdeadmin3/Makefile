# $NetBSD: Makefile,v 1.17 2004/01/03 18:49:47 reed Exp $

DISTNAME=	kdeadmin-3.1.4
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	System administration tools for the KDE integrated X11 desktop
PKGREVISION=	1

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-shadow
.else
CONFIGURE_ARGS+=	--without-shadow
.endif

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
