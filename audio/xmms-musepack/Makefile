# $NetBSD: Makefile,v 1.19 2012/03/03 00:12:45 wiz Exp $
#

DISTNAME=		xmms-musepack-1.1
PKGREVISION=		5
CATEGORIES=		audio
MASTER_SITES=		http://musepack.imosnet.de/linux/plugins/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.musepack.net/
COMMENT=		XMMS plugin for musepack (mpc) files

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../audio/libmusepack/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
