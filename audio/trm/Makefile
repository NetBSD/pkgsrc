# $NetBSD: Makefile,v 1.13 2012/10/02 23:48:12 asau Exp $
#

DISTNAME=	trm-0.2.1
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.musicbrainz.org/products/trmgen/download.html
COMMENT=	Acoustic signature generator

CONFLICTS=	tunepimp-[0-9]*

PKG_INSTALLATION_TYPES= overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++

AUTOMAKE_REQD=	1.6.3
USE_TOOLS+=	automake aclocal autoheader autoconf

INSTALLATION_DIRS+=	bin

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
