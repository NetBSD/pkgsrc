# $NetBSD: Makefile,v 1.7 2003/08/02 05:22:57 mrg Exp $

DISTNAME=	mjpegtools-1.6.1
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mjpeg/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mjpeg
COMMENT=	Programs for compressing video streams

DEPENDS+=		toolame>=02l:../../audio/toolame
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

USE_BUILDLINK2=		yes
USE_GMAKE=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-large-file
CONFIGURE_ARGS+=	--with-lame-includes=${BUILDLINK_PREFIX.lame}
# XXX fix me
CONFIGURE_ARGS+=	--without-avifile

.include "../../audio/lame/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
#.include "../../graphics/avifile/buildlink2.mk"
.include "../../graphics/ImageMagick/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
