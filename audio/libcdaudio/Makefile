# $NetBSD: Makefile,v 1.23 2004/11/26 13:38:30 adam Exp $

DISTNAME=	libcdaudio-0.99.12
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcdaudio/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://libcdaudio.sourceforge.net/
COMMENT=	Multi-platform CD player development library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	libcdaudio.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
