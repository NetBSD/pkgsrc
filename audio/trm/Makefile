# $NetBSD: Makefile,v 1.8 2006/02/05 23:08:14 joerg Exp $
#

DISTNAME=	trm-0.2.1
PKGREVISION=	3
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
