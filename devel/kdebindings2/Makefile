# $NetBSD: Makefile,v 1.16 2004/10/03 00:13:29 tv Exp $

DISTNAME=	kdebindings-2.2.1
PKGREVISION=	7
CATEGORIES=	devel
COMMENT=	Additional language bindings for KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--without-java
CONFIGURE_ENV+=		ac_cv_have_mozilla=no
CONFIGURE_ENV+=		PYTHONINC="-Ino"
CONFIGURE_ENV+=		PYTHONLIB="-Lno"

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/kde2/kde2.mk"
.include "../../x11/kdebase2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
