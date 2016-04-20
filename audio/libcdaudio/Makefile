# $NetBSD: Makefile,v 1.35 2016/04/20 12:10:27 nros Exp $

DISTNAME=	libcdaudio-0.99.12
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcdaudio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libcdaudio.sourceforge.net/
COMMENT=	Multi-platform CD player development library
LICENSE=	gnu-gpl-v2

NOT_FOR_PLATFORM=	Interix-*-*

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	libcdaudio.pc.in
REPLACE_SH=		libcdaudio-config.in

.include "../../mk/bsd.pkg.mk"
