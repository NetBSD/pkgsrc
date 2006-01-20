# $NetBSD: Makefile,v 1.11 2006/01/20 16:15:52 jmmv Exp $
#

DISTNAME=		xmms-musepack-1.1
CATEGORIES=		audio
MASTER_SITES=		http://musepack.imosnet.de/linux/plugins/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.musepack.net/
COMMENT=		XMMS plugin for musepack (mpc) files

USE_LANGUAGES=		c++
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../audio/libmusepack/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
