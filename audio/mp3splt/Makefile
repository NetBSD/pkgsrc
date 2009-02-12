# $NetBSD: Makefile,v 1.16 2009/02/12 22:52:49 drochner Exp $
#

DISTNAME=		mp3splt-2.2.3
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mp3splt/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://mp3splt.sourceforge.net/
COMMENT=		Command line utility to split MP3 (VBR supported) and OGG files

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=	 	yes
USE_FEATURES= 	 	getopt_long

.include "../../audio/libmp3splt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
