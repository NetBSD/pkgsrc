# $NetBSD: Makefile,v 1.13 2009/05/19 08:59:03 wiz Exp $

DISTNAME=	fluidsynth-1.0.9
CATEGORIES=	audio
MASTER_SITES=	http://savannah.nongnu.org/download/fluid/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/fluid/
COMMENT=	Software synthesizer based on SoundFont2
LICENSE=	gnu-lgpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	fluidsynth.pc.in
PTHREAD_AUTO_VARS=	yes

CFLAGS+=		-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
LDFLAGS+=		${LIBOSSAUDIO}

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
