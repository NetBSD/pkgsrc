# $NetBSD: Makefile,v 1.15 2017/04/26 14:04:08 maya Exp $

DISTNAME=		mpeg4ip-1.6.1
PKGNAME=		libmp4v2-1.6.1
PKGREVISION=		4
CATEGORIES=		multimedia
# distfile at sf is corrupt
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mpeg4ip/}
MASTER_SITES=		${MASTER_SITE_FREEBSD_LOCAL:=ahze/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mpeg4ip.sourceforge.net/
COMMENT=		Library for reading and modifying mp4 files

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	USENASM=no
# the "bootstrap" script checks too much, and isn't useful anyway
#CONFIGURE_SCRIPT=	bootstrap

GCC_REQD+=		5.4

# libmp4v2 has config.{guess,sub} also in common/video/iso-mpeg4
# (unused by libmp4v2 build)
OVERRIDE_DIRDEPTH=	3

# to install mp4* tools
BUILD_DIRS=		. lib/mp4v2/util

BUILDLINK_TRANSFORM+=   rm:-Werror

pre-configure:
	${TOUCH} ${WRKSRC}/bootstrapped

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
