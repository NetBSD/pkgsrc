# $NetBSD: Makefile,v 1.5 2006/03/09 21:04:44 jlam Exp $

VERSION=	0.7
DISTNAME=	gr-audio-oss-${VERSION}
PKGNAME=	gnuradio-audio-oss-${VERSION}
PKGREVISION=	2
WRKSRC=		${WRKDIR}/${DISTNAME}
COMMENT=	Open Sound System support for GNU Radio

.include "../../meta-pkgs/gnuradio/Makefile.common"

.include "../../mk/oss.buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
