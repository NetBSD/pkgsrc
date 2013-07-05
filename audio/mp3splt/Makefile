# $NetBSD: Makefile,v 1.23 2013/07/05 16:15:59 ryoon Exp $
#

DISTNAME=		mp3splt-2.5.2
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mp3splt/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://mp3splt.sourceforge.net/
COMMENT=		Command line utility to split MP3 (VBR supported) and OGG files
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=	 	yes
USE_FEATURES= 	 	getopt_long
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--disable-nls

.include "../../audio/libmp3splt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
