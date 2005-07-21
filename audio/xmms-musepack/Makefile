# $NetBSD: Makefile,v 1.8 2005/07/21 16:29:44 wiz Exp $
#

DISTNAME=		xmms-musepack-1.1
CATEGORIES=		audio
MASTER_SITES=		http://www.saunalahti.fi/grimmel/musepack.net/linux/plugins/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.musepack.net/
COMMENT=		XMMS plugin for musepack (mpc) files

USE_LANGUAGES=		c++
GNU_CONFIGURE=		yes

.include "../../audio/libmusepack/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
