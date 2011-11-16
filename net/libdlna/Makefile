# $NetBSD: Makefile,v 1.2 2011/11/16 01:33:16 sbd Exp $
#

DISTNAME=	libdlna-0.2.3
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://libdlna.geexbox.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://libdlna.geexbox.org/
COMMENT=	Reference DLNA open-source implementation
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE=		libdlna.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-ffmpeg-dir=${BUILDLINK_PREFIX.ffmpeg}

MAKE_JOBS_SAFE=		no

.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
