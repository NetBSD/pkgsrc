# $NetBSD: Makefile,v 1.30 2023/08/02 19:20:17 nia Exp $
#

DISTNAME=	xmms-musepack-1.1
PKGREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	http://musepack.imosnet.de/linux/plugins/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.musepack.net/
COMMENT=	XMMS plugin for musepack (mpc) files
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

.include "../../audio/libmusepack/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
