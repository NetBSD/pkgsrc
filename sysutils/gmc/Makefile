# $NetBSD: Makefile,v 1.33 2003/11/12 01:31:51 salo Exp $

PKGNAME=		g${DISTNAME}
PKGREVISION=		6
CATEGORIES+=		gnome

COMMENT=		GNOME version of Midnight Commander, a free Norton Commander Clone

USE_X11BASE=		# defined
CONFIGURE_ARGS+=	--with-tm-x-support
CONFIGURE_ARGS+=	--with-gnome
BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome1-dirs>=1.2:../../misc/gnome1-dirs

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/gmc/C/figs

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../sysutils/mc/Makefile.common"
