# $NetBSD: Makefile,v 1.13 2007/02/02 01:05:20 joerg Exp $

DISTNAME=		xzip180
PKGNAME=		xzip-1.8
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://www.eblong.com/zarf/ftp/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.eblong.com/zarf/xzip.html
COMMENT=		Z-code interpreter for X11 (Infocom game format)

WRKSRC=			${WRKDIR}/xzip
USE_X11BASE=		yes
BUILD_TARGET=		xzip

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
