# $NetBSD: Makefile,v 1.13 2008/11/18 22:08:32 rillig Exp $

SNAPSHOT_DATE=		20071218

DISTNAME=		x264-snapshot-${SNAPSHOT_DATE}-2245
PKGNAME=		x264-devel-${SNAPSHOT_DATE}
PKGREVISION=		2
CATEGORIES=		multimedia
MASTER_SITES=		ftp://ftp.videolan.org/pub/videolan/x264/snapshots/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://www.videolan.org/developers/x264.html
COMMENT=		GPL licensed H.264 encoder

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=	yasm>=0.4.0:../../devel/yasm
.endif

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
.if ${INSTALL_UNSTRIPPED:Uno:M[Yy][Ee][Ss]}
CONFIGURE_ARGS+=	--enable-debug
.endif
MAKE_ENV+=		SH=${SH:Q}

BUILD_TARGET=		default

post-extract:
	${SED} -e 's,@SH@,${SH},' ${FILESDIR}/strip_fopt.sh \
	  >${WRKSRC}/strip_fopt.sh
	${CHMOD} +x ${WRKSRC}/strip_fopt.sh

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
