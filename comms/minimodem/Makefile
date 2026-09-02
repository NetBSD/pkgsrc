# $NetBSD: Makefile,v 1.10 2026/09/02 19:01:13 wiz Exp $

DISTNAME=	minimodem-0.24
PKGREVISION=	8
CATEGORIES=	comms audio
MASTER_SITES=	http://www.whence.com/minimodem/ # https times out

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.whence.com/minimodem/
COMMENT=	General-purpose software audio FSK modem
LICENSE=	gnu-gpl-v3 # or later

GNU_CONFIGURE=	yes

USE_TOOLS+=	pkg-config

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
