# $NetBSD: Makefile,v 1.68 2025/10/05 19:25:42 js Exp $

DISTNAME=	vorbis-tools-1.0
PKGNAME=	tremor-tools-1.0.0.8
PKGREVISION=	48
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/vorbis/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xiph.org/vorbis/
COMMENT=	Ogg Vorbis encoder and player
LICENSE=	gnu-gpl-v2

BUILD_DEFS+=	IPV6_READY

CONFLICTS=	vorbis-[0-9]*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		automake14 gmake

PLIST_SUBST+=	DISTNAME=${DISTNAME:Q}

PTHREAD_OPTS+=	require

pre-configure:
	touch ${WRKSRC}/aclocal.m4
	cd ${WRKSRC} && automake && autoconf

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/tremor/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
