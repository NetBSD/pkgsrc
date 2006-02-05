# $NetBSD: Makefile,v 1.11 2006/02/05 23:08:17 joerg Exp $
#

DISTNAME=	arts_output-0.7.1
PKGNAME=	xmms-arts-0.7.1
PKGREVISION=	2
CATEGORIES=	audio kde
MASTER_SITES=	http://havardk.xmms.org/plugins/arts_output/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.xmms.org/plugins.php?category=output
COMMENT=	XMMS plugin to output sound through the aRts sound daemon

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	libtool

LIBS+=			${LIBOSSAUDIO}

.include "../../audio/arts/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
