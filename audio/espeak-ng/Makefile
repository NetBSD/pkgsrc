# $NetBSD: Makefile,v 1.2 2024/03/25 17:18:35 jperkin Exp $

DISTNAME=	espeak-ng-1.51
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=espeak-ng/}
GITHUB_TAG=	refs/tags/1.51

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/espeak-ng/espeak-ng/
COMMENT=	Open source speech synthesizer
LICENSE=	gnu-gpl-v3 AND apache-2.0 AND 2-clause-bsd AND unicode

DEPENDS+=	mbrola-[0-9]*:../../audio/mbrola

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	autoconf automake autoreconf gmake
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

TEST_TARGET=	check

.include "../../mk/bsd.prefs.mk"

# -D_NETBSD_SOURCE for mkstemp in /usr/include/stdlib.h
.if ${OPSYS} == "NetBSD"
CFLAGS+=	-D_NETBSD_SOURCE
.endif

CONFIGURE_ARGS+=	CFLAGS=${CFLAGS:M*:Q}

PKGCONFIG_OVERRIDE+=	espeak-ng.pc.in

SUBST_CLASSES+=		mbrola
SUBST_STAGE.mbrola=	pre-configure
SUBST_FILES.mbrola=	src/libespeak-ng/synth_mbrola.c
SUBST_SED.mbrola=	-e s,/usr/share/mbrola/%s/%s,${PREFIX}/share/mbrola/voices/%s/%s,g
SUBST_MESSAGE.mbrola=	Fixing hardcoded mbrola path.

# Makefile.am: error: required file './AUTHORS' not found
pre-configure:
	set -e; cd ${WRKSRC} && touch AUTHORS NEWS && autoreconf -fi

.include "options.mk"
.include "../../audio/pcaudiolib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
