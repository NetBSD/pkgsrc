# $NetBSD: Makefile,v 1.25 2020/05/20 06:09:05 rillig Exp $

DISTNAME=		mpeg4ip-1.6.1
PKGNAME=		libmp4v2-1.6.1
PKGREVISION=		8
CATEGORIES=		multimedia
# distfile at sf is corrupt
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mpeg4ip/}
MASTER_SITES=		${MASTER_SITE_FREEBSD_LOCAL:=ahze/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mpeg4ip.sourceforge.net/
COMMENT=		Library for reading and modifying mp4 files

USE_LANGUAGES=		c c++03
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	USENASM=no
# the "bootstrap" script checks too much, and isn't useful anyway
#CONFIGURE_SCRIPT=	bootstrap

# libmp4v2 has config.{guess,sub} also in common/video/iso-mpeg4
# (unused by libmp4v2 build)
OVERRIDE_DIRDEPTH=	3

# to install mp4* tools
BUILD_DIRS=		. lib/mp4v2/util

# lowercase min,max cannot be used as macros, conflicts with libstdc++6
SUBST_CLASSES+=		minmax
SUBST_STAGE.minmax=	pre-configure
SUBST_FILES.minmax=	common/video/iso-mpeg4/src/*
SUBST_SED.minmax=	-e 's,min *(,MIN(,g' -e 's,max *(,MAX(,g'
SUBST_MESSAGE.minmax=	replace lowercase min,max with uppercase

# util.c: In function 'quicktime_read_pascal':
# util.c:138:6: error: array subscript has type 'char' [-Werror=char-subscripts]
#   data[len] = 0;
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

pre-configure:
	${TOUCH} ${WRKSRC}/bootstrapped

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
