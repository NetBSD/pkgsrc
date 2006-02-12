# $NetBSD: Makefile,v 1.1.1.1 2006/02/12 14:11:22 joerg Exp $
#

SNAPSHOT_DATE=		20060127

DISTNAME=		x264-snapshot-${SNAPSHOT_DATE}-2245
PKGNAME=		x264-devel-${SNAPSHOT_DATE}
CATEGORIES=		multimedia
MASTER_SITES=		ftp://ftp.videolan.org/pub/videolan/x264/snapshots/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://developers.videolan.org/x264.html
COMMENT=		GPL licensed H.264 encoder

USE_TOOLS+=		gmake

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

BUILD_TARGET=		default

.include "../../mk/bsd.pkg.mk"
