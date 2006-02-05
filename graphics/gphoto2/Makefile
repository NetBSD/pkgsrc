# $NetBSD: Makefile,v 1.36 2006/02/05 23:09:32 joerg Exp $

DISTNAME=	gphoto2-2.1.6
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gphoto.sourceforge.net/proj/gphoto2/
COMMENT=	Digital camera access command line client

CONFLICTS=	gphoto-[0-9]*

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-aalib-prefix=${BUILDLINK_PREFIX.aalib}
CONFIGURE_ARGS+=	--with-cdk-prefix=${BUILDLINK_PREFIX.cdk}
CONFIGURE_ARGS+=	--with-exif-prefix=${BUILDLINK_PREFIX.libexif}
CONFIGURE_ARGS+=	--with-jpeg-prefix=${BUILDLINK_PREFIX.jpeg}

SUBST_CLASSES+=		libexif-update
SUBST_STAGE.libexif-update=	pre-configure
SUBST_MESSAGE.libexif-update=	Fix configure script checks for libexif-0.6.13
SUBST_FILES.libexif-update=	configure
SUBST_SED.libexif-update=	s,exif-,libexif/exif-,g

# readline detection is currently broken since -ltermcap isn't passed as
# part of the library check.
#
CONFIGURE_ARGS+=	--without-readline
#USE_GNU_READLINE=	rl_completion_matches, rl_completion_append_character
#.include "../../devel/readline/buildlink3.mk"

.include "../../devel/cdk/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
