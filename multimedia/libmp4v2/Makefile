# $NetBSD: Makefile,v 1.11.36.1 2017/04/23 10:32:09 bsiegert Exp $

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

CONFLICTS+=		mpeg4ip<1.5.0.1 mp4v2-[0-9]*

USE_LANGUAGES=		c c++
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

BUILDLINK_TRANSFORM+=   rm:-Werror

pre-configure:
	${TOUCH} ${WRKSRC}/bootstrapped

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
