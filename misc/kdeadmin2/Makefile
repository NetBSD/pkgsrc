# $NetBSD: Makefile,v 1.8 2002/12/05 12:23:39 tron Exp $

DISTNAME=	kdeadmin-2.2.2
PKGREVISION=	2
CATEGORIES=	misc
COMMENT=	Utilities for the KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK2=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-shadow
.else
CONFIGURE_ARGS+=	--without-shadow
.endif

.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
