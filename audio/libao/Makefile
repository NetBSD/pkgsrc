# $NetBSD: Makefile,v 1.13.2.2 2002/06/21 23:04:57 jlam Exp $

DISTNAME=	libao-0.8.2
CATEGORIES=	devel
MASTER_SITES=	http://www.vorbis.com/files/rc3/unix/

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
