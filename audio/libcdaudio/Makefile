# $NetBSD: Makefile,v 1.30 2008/11/21 10:38:19 drochner Exp $

DISTNAME=	libcdaudio-0.99.12
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcdaudio/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://libcdaudio.sourceforge.net/
COMMENT=	Multi-platform CD player development library

NOT_FOR_PLATFORM=	Interix-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	libcdaudio.pc.in

.include "../../mk/bsd.pkg.mk"
