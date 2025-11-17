# $NetBSD: Makefile,v 1.40 2025/11/17 11:00:18 wiz Exp $

DISTNAME=	libcdaudio-0.99.12
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcdaudio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libcdaudio.sourceforge.net/
COMMENT=	Multi-platform CD player development library
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	libcdaudio.pc.in
REPLACE_SH=		libcdaudio-config.in

.include "../../mk/bsd.pkg.mk"
