# $NetBSD: Makefile,v 1.16 2024/12/28 21:56:22 adam Exp $

DISTNAME=	libdiscid-0.6.4
CATEGORIES=	audio
MASTER_SITES=	http://ftp.musicbrainz.org/pub/musicbrainz/libdiscid/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://musicbrainz.org/doc/libdiscid
COMMENT=	Library for creating MusicBrainz DiscIDs
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	libdiscid.pc.in

.include "../../mk/bsd.pkg.mk"
