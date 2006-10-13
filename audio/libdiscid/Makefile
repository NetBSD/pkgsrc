# $NetBSD: Makefile,v 1.1.1.1 2006/10/13 02:31:56 epg Exp $

DISTNAME=	libdiscid-0.1.0
CATEGORIES=	audio
MASTER_SITES=	http://users.musicbrainz.org/~matt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/libdiscid
COMMENT=	Library for creating MusicBrainz DiscIDs

# XXX We don't yet have libmusicbrainz, so this could be wrong; it
# might end up packaged as libmusicbrainz3, for example.
CONFLICTS=	libmusicbrainz>=3.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libdiscid.pc.in

.include "../../mk/bsd.pkg.mk"
