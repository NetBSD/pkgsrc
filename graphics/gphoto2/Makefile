# $NetBSD: Makefile,v 1.20 2003/09/28 09:13:57 jlam Exp $
#

DISTNAME=	gphoto2-2.1.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gphoto.sourceforge.net/proj/gphoto2/
COMMENT=	Digital camera access command line client

CONFLICTS=	gphoto-[0-9]*

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-aalib-prefix=${BUILDLINK_PREFIX.aalib}
CONFIGURE_ARGS+=	--with-cdk-prefix=${BUILDLINK_PREFIX.cdk}
CONFIGURE_ARGS+=	--with-exif-prefix=${BUILDLINK_PREFIX.libexif}
CONFIGURE_ARGS+=	--with-jpeg-prefix=${BUILDLINK_PREFIX.jpeg}

# readline detection is currently broken since -ltermcap isn't passed as
# part of the library check.
#
CONFIGURE_ARGS+=	--without-readline
#USE_GNU_READLINE=	rl_completion_matches, rl_completion_append_character
#.include "../../devel/readline/buildlink2.mk"

.include "../../devel/cdk/buildlink2.mk"
.include "../../devel/libgphoto2/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../graphics/aalib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
