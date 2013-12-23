# $NetBSD: Makefile,v 1.33 2013/12/23 11:57:02 wiz Exp $

DISTNAME=	libcdaudio-0.99.12
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcdaudio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libcdaudio.sourceforge.net/
COMMENT=	Multi-platform CD player development library

NOT_FOR_PLATFORM=	Interix-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	libcdaudio.pc.in
REPLACE_SH=		libcdaudio-config.in

.include "../../mk/bsd.pkg.mk"
