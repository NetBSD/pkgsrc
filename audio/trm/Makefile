# $NetBSD: Makefile,v 1.2 2004/02/21 06:27:17 snj Exp $

DISTNAME=	trm-0.2.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	chris@NetBSD.org
HOMEPAGE=	http://www.musicbrainz.org/products/trmgen/download.html
COMMENT=	Acoustic signature generator

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
