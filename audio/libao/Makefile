# $NetBSD: Makefile,v 1.11 2001/10/04 04:01:00 jlam Exp $

DISTNAME=	libao-0.8.0
CATEGORIES=	devel
MASTER_SITES=	http://www.vorbis.com/files/rc2/unix/

MAINTAINER=	lukem@netbsd.org
COMMENT=	cross-platform audio library

BUILD_DEPENDS+=	automake>=1.4:../../devel/automake

PLIST_SUBST+=	VERSION="${DISTNAME}"

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-arts
CONFIGURE_ARGS+=	--disable-esd

USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
