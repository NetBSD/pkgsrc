# $NetBSD: Makefile,v 1.11 2005/06/01 18:02:53 jlam Exp $

DISTNAME=		xzip180
PKGNAME=		xzip-1.8
CATEGORIES=		games x11
MASTER_SITES=		http://www.eblong.com/zarf/ftp/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.eblong.com/zarf/xzip.html
COMMENT=		Z-code interpreter for X11 (Infocom game format)

WRKSRC=			${WRKDIR}/xzip
USE_X11BASE=		yes
BUILD_TARGET=		xzip

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
