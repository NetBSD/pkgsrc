# $NetBSD: Makefile,v 1.30 2003/05/02 11:56:22 wiz Exp $

PKGNAME=		g${DISTNAME}
PKGREVISION=		3
CATEGORIES+=		gnome

COMMENT=		GNOME version of Midnight Commander, a free Norton Commander Clone

USE_X11BASE=		# defined
CONFIGURE_ARGS+=	--with-tm-x-support
CONFIGURE_ARGS+=	--with-gnome
BUILD_USES_MSGFMT=	yes

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/gmc/C/figs

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../sysutils/mc/Makefile.common"
