# $NetBSD: Makefile,v 1.39 2004/10/03 00:18:15 tv Exp $

PKGNAME=		g${DISTNAME}
PKGREVISION=		10
CATEGORIES+=		gnome

COMMENT=		GNOME version of Midnight Commander, a free Norton Commander Clone

USE_DIRS+=		gnome1-1.5
USE_X11BASE=		# defined
CONFIGURE_ARGS+=	--with-tm-x-support
CONFIGURE_ARGS+=	--with-gnome
BUILD_USES_MSGFMT=	yes

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/gmc/C/figs

.include "../../x11/gnome-core/buildlink3.mk"
.include "../../sysutils/mc/Makefile.common"
