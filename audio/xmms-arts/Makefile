# $NetBSD: Makefile,v 1.3 2003/12/08 14:41:38 wiz Exp $
#

DISTNAME=	xmmsarts-0.4
PKGNAME=	${DISTNAME:S/xmms/xmms-/}
PKGREVISION=			1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	audio kde
MASTER_SITES=	http://stukach.com/hosted/m.i.a/xmmsarts/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.xmms.org/plugins.php?category=output
COMMENT=	XMMS plugin to output sound through the aRts sound daemon

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

LIBS+=			${LIBOSSAUDIO}

.include "../../audio/arts/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
