# $NetBSD: Makefile,v 1.8 2006/12/27 13:37:36 joerg Exp $

DISTNAME=		cbzone-sound
PKGNAME=		cbzone-2.0c
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		ftp://ftp.cdrom.com/pub/X11/R5contrib/

MAINTAINER=		root@garbled.net
COMMENT=		Simple classic game of 3D tank warfare

WRKSRC=			${WRKDIR}/cbzone
USE_TOOLS+=		gmake
USE_IMAKE=		yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
