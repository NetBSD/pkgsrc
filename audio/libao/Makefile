# $NetBSD: Makefile,v 1.15 2002/08/25 18:38:09 jlam Exp $

DISTNAME=	libao-0.8.3
CATEGORIES=	devel
MASTER_SITES=	http://www.vorbis.com/files/1.0/unix/

MAINTAINER=	lukem@netbsd.org
COMMENT=	cross-platform audio library

PLIST_SUBST+=	VERSION="${DISTNAME}"

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-arts
CONFIGURE_ARGS+=	--disable-esd

USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
