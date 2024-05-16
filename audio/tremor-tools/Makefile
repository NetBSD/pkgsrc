# $NetBSD: Makefile,v 1.60 2024/05/16 06:14:35 wiz Exp $

DISTNAME=	vorbis-tools-1.0
PKGNAME=	tremor-tools-1.0.0.8
PKGREVISION=	41
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/1.0/unix/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vorbis.com/
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
