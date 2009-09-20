# $NetBSD: Makefile,v 1.6 2009/09/20 21:40:37 sno Exp $

DISTNAME=	libdiscid-0.2.2
CATEGORIES=	audio
MASTER_SITES=	http://users.musicbrainz.org/~matt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/libdiscid
COMMENT=	Library for creating MusicBrainz DiscIDs

ONLY_FOR_PLATFORM=	Darwin-*-* Linux-*-* NetBSD-*-* FreeBSD-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libdiscid.pc.in
PKG_DESTDIR_SUPPORT= user-destdir

.include "../../mk/bsd.pkg.mk"
