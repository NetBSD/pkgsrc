# $NetBSD: Makefile,v 1.18 2026/07/08 10:10:21 adam Exp $

DISTNAME=	libdiscid-0.7.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=metabrainz/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

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
