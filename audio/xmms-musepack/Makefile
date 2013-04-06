# $NetBSD: Makefile,v 1.23 2013/04/06 14:22:39 rodent Exp $
#

DISTNAME=	xmms-musepack-1.1
PKGREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://musepack.imosnet.de/linux/plugins/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.musepack.net/
COMMENT=	XMMS plugin for musepack (mpc) files

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../audio/libmusepack/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
