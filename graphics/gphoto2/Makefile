# $NetBSD: Makefile,v 1.10 2002/09/10 16:06:42 wiz Exp $

DISTNAME=	gphoto2-2.1.0
PKGNAME=	gphoto-2.1.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.gphoto.org/gphoto2/
COMMENT=	Download and view files from various digital cameras

BUILD_USES_MSGFMT=	# defined

USE_BUILDLINK2=		# defined
USE_GMAKE=		# defined

USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libgphoto2_port/libtool

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-drivers=all
CONFIGURE_ARGS+=	--with-doc-dir=${PREFIX}/share/doc/gphoto2
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html/gphoto2
CONFIGURE_ARGS+=	--without-pthread
CONFIGURE_ARGS+=	--without-pkgconfig
CONFIGURE_ARGS+=	--without-fig2dev
CONFIGURE_ARGS+=	--without-xmlto
CONFIGURE_ARGS+=	--with-aalib
CONFIGURE_ARGS+=	--with-cdk-prefix=${BUILDLINK_PREFIX.cdk}
CONFIGURE_ARGS+=	--with-exif-prefix=${BUILDLINK_PREFIX.libexif}
CONFIGURE_ARGS+=	--with-jpeg-prefix=${BUILDLINK_PREFIX.jpeg}

# readline detection is currently broken since -ltermcap isn't passed as
# part of the library check.
#
CONFIGURE_ARGS+=	--without-readline
#USE_GNU_READLINE=	rl_completion_matches
#.include "../../devel/readline/buildlink2.mk"

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/cdk/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../devel/libusb/buildlink2.mk"
.include "../../graphics/aalib/buildlink2.mk"
.include "../../graphics/libexif/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
