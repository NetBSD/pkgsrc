# $NetBSD: Makefile,v 1.3 2007/06/08 06:42:32 wiz Exp $

DISTNAME=	libdiscid-0.1.0
CATEGORIES=	audio
MASTER_SITES=	http://users.musicbrainz.org/~matt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/libdiscid
COMMENT=	Library for creating MusicBrainz DiscIDs

ONLY_FOR_PLATFORM=	Darwin-*-* Linux-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libdiscid.pc.in

.include "../../mk/bsd.pkg.mk"
