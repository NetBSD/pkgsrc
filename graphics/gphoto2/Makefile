# $NetBSD: Makefile,v 1.7 2002/07/12 21:22:21 mycroft Exp $

DISTNAME=	gphoto2-2.1.0
PKGNAME=	gphoto-2.1.0

CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.gphoto.org/gphoto2/
COMMENT=	Download and view files from various digital cameras

USE_BUILDLINK_ONLY=	# XXX gphoto2 adds unneeded -L${LOCALBASE}/lib etc.

BUILD_USES_MSGFMT=	# defined

USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
USE_GNU_READLINE=	rl_completion_matches
LIBTOOL_OVERRIDE=	${WRKSRC}/ltmain.sh
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-drivers=all
CONFIGURE_ARGS+=	--with-doc-dir=${PREFIX}/share/doc/gphoto2
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html/gphoto2
CONFIGURE_ARGS+=	--without-pkgconfig
CONFIGURE_ARGS+=	--without-fig2dev
CONFIGURE_ARGS+=	--with-aalib
CONFIGURE_ARGS+=	--with-cdk
CONFIGURE_ARGS+=	--with-exif
CONFIGURE_ARGS+=	--with-jpeg-prefix=${PREFIX}

BUILDLINK_DEPENDS.libusb=   libusb>=0.1.5

.include "../../converters/libiconv/buildlink.mk"
.include "../../devel/cdk/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/libusb/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../graphics/aalib/buildlink.mk"
.include "../../graphics/libexif/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
