# $NetBSD: Makefile,v 1.6 2004/03/11 23:04:46 snj Exp $
#

DISTNAME=	xmmsarts-0.4
PKGNAME=	${DISTNAME:S/xmms/xmms-/}
PKGREVISION=			1
CATEGORIES=	audio kde
MASTER_SITES=	http://stukach.com/hosted/m.i.a/xmmsarts/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.xmms.org/plugins.php?category=output
COMMENT=	XMMS plugin to output sound through the aRts sound daemon

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
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
