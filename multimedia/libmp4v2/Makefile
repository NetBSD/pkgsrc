# $NetBSD: Makefile,v 1.11 2012/12/03 22:26:17 wiz Exp $

DISTNAME=		mpeg4ip-1.6.1
PKGNAME=		libmp4v2-1.6.1
PKGREVISION=		3
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

BUILD_DIRS=		lib/mp4v2
INSTALL_DIRS+=		lib/mp4v2 doc/mp4v2

pre-configure:
	${TOUCH} ${WRKSRC}/bootstrapped

.include "../../mk/bsd.pkg.mk"
