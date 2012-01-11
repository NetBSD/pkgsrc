# $NetBSD: Makefile,v 1.21 2012/01/11 19:35:35 hans Exp $
#

DISTNAME=		mp3splt-2.4
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mp3splt/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://mp3splt.sourceforge.net/
COMMENT=		Command line utility to split MP3 (VBR supported) and OGG files
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=	 	yes
USE_FEATURES= 	 	getopt_long

CONFIGURE_ARGS+=	--disable-nls

.include "../../audio/libmp3splt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
