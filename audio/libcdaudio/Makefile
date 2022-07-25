# $NetBSD: Makefile,v 1.38 2022/07/25 11:12:19 wiz Exp $

DISTNAME=	libcdaudio-0.99.12
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcdaudio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libcdaudio.sourceforge.net/
COMMENT=	Multi-platform CD player development library
LICENSE=	gnu-gpl-v2

NOT_FOR_PLATFORM=	Interix-*-*

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	libcdaudio.pc.in
REPLACE_SH=		libcdaudio-config.in

.include "../../mk/bsd.pkg.mk"
