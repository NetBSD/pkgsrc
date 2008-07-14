# $NetBSD: Makefile,v 1.10 2008/07/14 12:55:58 joerg Exp $
#

DISTNAME=	mp3info-0.2.16
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/sound/editors/}

MAINTAINER=	simonb@NetBSD.org
COMMENT=	MP3 header and tag information tool

CONFLICTS=	gmp3info-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
