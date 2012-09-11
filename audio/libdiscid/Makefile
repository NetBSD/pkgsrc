# $NetBSD: Makefile,v 1.8 2012/09/12 00:24:42 asau Exp $

DISTNAME=	libdiscid-0.2.2
CATEGORIES=	audio
MASTER_SITES=	http://users.musicbrainz.org/~matt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/libdiscid
COMMENT=	Library for creating MusicBrainz DiscIDs
LICENSE=	gnu-lgpl-v2.1

ONLY_FOR_PLATFORM=	Darwin-*-* DragonFly-*-* FreeBSD-*-* Linux-*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libdiscid.pc.in

.include "../../mk/bsd.pkg.mk"
