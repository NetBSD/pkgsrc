# $NetBSD: Makefile,v 1.13 2002/03/05 17:38:49 skrll Exp $

DISTNAME=	libao-0.8.2
CATEGORIES=	devel
MASTER_SITES=	http://www.vorbis.com/files/rc3/unix/

MAINTAINER=	lukem@netbsd.org
COMMENT=	cross-platform audio library

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
