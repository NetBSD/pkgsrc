# $NetBSD: Makefile,v 1.35 2004/03/08 19:40:42 jmmv Exp $

PKGNAME=		g${DISTNAME}
PKGREVISION=		8
CATEGORIES+=		gnome

COMMENT=		GNOME version of Midnight Commander, a free Norton Commander Clone

USE_X11BASE=		# defined
CONFIGURE_ARGS+=	--with-tm-x-support
CONFIGURE_ARGS+=	--with-gnome
BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome1-dirs>=1.5:../../misc/gnome1-dirs

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/gmc/C/figs

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../sysutils/mc/Makefile.common"
