# $NetBSD: Makefile,v 1.7 2006/01/24 07:31:55 wiz Exp $
#

DISTNAME=	trm-0.2.1
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	chris@NetBSD.org
HOMEPAGE=	http://www.musicbrainz.org/products/trmgen/download.html
COMMENT=	Acoustic signature generator

CONFLICTS=	tunepimp-[0-9]*

PKG_INSTALLATION_TYPES= overwrite pkgviews

GNU_CONFIGURE=		YES

.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
