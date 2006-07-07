# $NetBSD: Makefile,v 1.13 2006/07/07 15:49:30 jlam Exp $
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
SHLIBTOOL_OVERRIDE=	# empty

LIBS+=			${LIBOSSAUDIO}

.include "../../audio/arts/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
