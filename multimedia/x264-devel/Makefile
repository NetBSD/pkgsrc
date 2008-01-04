# $NetBSD: Makefile,v 1.5 2008/01/04 18:41:54 joerg Exp $
#

SNAPSHOT_DATE=		20071218

DISTNAME=		x264-snapshot-${SNAPSHOT_DATE}-2245
PKGNAME=		x264-devel-${SNAPSHOT_DATE}
CATEGORIES=		multimedia
MASTER_SITES=		ftp://ftp.videolan.org/pub/videolan/x264/snapshots/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://www.videolan.org/developers/x264.html
COMMENT=		GPL licensed H.264 encoder

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=	nasm>=0.98.34:../../devel/nasm
.elif ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=	yasm>=0.4.0:../../devel/yasm
.endif

USE_TOOLS+=		gmake

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

BUILD_TARGET=		default

.include "../../mk/bsd.pkg.mk"
