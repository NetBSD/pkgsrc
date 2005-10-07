# $NetBSD: Makefile,v 1.1.1.1 2005/10/07 23:17:19 wulf Exp $

VERSION=	0.6
DISTNAME=	gr-audio-oss-${VERSION}
PKGNAME=	gnuradio-audio-oss-${VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}
COMMENT=	Open Sound System support for GNU Radio

.include "../../meta-pkgs/gnuradio/Makefile.common"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
