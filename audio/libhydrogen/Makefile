# $NetBSD: Makefile,v 1.8 2006/03/09 21:04:40 jlam Exp $

DISTNAME=	libhydrogen-0.8.0
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hydrogen/}

MAINTAINER=	chris.wareham@btinternet.com
HOMEPAGE=	http://hydrogen.sourceforge.net/
COMMENT=	Shared library for the Hydrogen drum machine

NOT_FOR_PLATFORM=	Interix-*-*

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-alsa-seq
CONFIGURE_ARGS+=	--disable-jack-support

CPPFLAGS+=		-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
