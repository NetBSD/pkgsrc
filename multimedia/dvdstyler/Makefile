# $NetBSD: Makefile,v 1.1.1.1 2006/01/24 03:47:44 xtraeme Exp $
#

DISTNAME=	DVDStyler-1.5b4
PKGNAME=	dvdstyler-1.5beta4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvdstyler/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://dvdstyler.sourceforge.net/
COMMENT=	Crossplatform DVD Authoring System

DEPENDS+=	dvdauthor>=0.6.10:../../multimedia/dvdauthor
DEPENDS+=	dvd+rw-tools-[0-9]*:../../sysutils/dvd+rw-tools
DEPENDS+=	mpgtx-[0-9]*:../../graphics/mpgtx

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

.include "../../graphics/wxsvg/buildlink3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
