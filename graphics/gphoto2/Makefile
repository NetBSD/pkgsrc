# $NetBSD: Makefile,v 1.26 2004/04/26 05:23:01 snj Exp $
#

DISTNAME=	gphoto2-2.1.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gphoto.sourceforge.net/proj/gphoto2/
COMMENT=	Digital camera access command line client

CONFLICTS=	gphoto-[0-9]*

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
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
#.include "../../devel/readline/buildlink3.mk"

.include "../../devel/cdk/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
