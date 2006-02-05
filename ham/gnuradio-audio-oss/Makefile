# $NetBSD: Makefile,v 1.4 2006/02/05 23:09:41 joerg Exp $

VERSION=	0.7
DISTNAME=	gr-audio-oss-${VERSION}
PKGNAME=	gnuradio-audio-oss-${VERSION}
PKGREVISION=	2
WRKSRC=		${WRKDIR}/${DISTNAME}
COMMENT=	Open Sound System support for GNU Radio

.include "../../meta-pkgs/gnuradio/Makefile.common"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
