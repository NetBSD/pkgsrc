# $NetBSD: Makefile,v 1.4 2005/04/11 21:44:54 tv Exp $

DISTNAME=	libhydrogen-0.8.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hydrogen/}

MAINTAINER=	chris.wareham@btinternet.com
HOMEPAGE=	http://hydrogen.sourceforge.net/
COMMENT=	Shared library for the Hydrogen drum machine

USE_LIBTOOL=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-alsa-seq
CONFIGURE_ARGS+=	--disable-jack-support

CPPFLAGS+=		-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
