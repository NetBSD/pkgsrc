# $NetBSD: Makefile,v 1.9 2026/09/02 19:00:46 wiz Exp $

DISTNAME=	espeak-ng-1.52.0
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=espeak-ng/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/espeak-ng/espeak-ng/
COMMENT=	Open source speech synthesizer
LICENSE=	gnu-gpl-v3 AND apache-2.0 AND 2-clause-bsd AND unicode

DEPENDS+=	mbrola-[0-9]*:../../audio/mbrola

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

CFLAGS.SunOS+=	-D_LARGEFILE64_SOURCE -D__EXTENSIONS__

PKGCONFIG_OVERRIDE+=	espeak-ng.pc.in

# Makefile.am: error: required file './AUTHORS' not found
pre-configure:
	set -e; cd ${WRKSRC} && touch AUTHORS NEWS && autoreconf -fi

.include "options.mk"
.include "../../audio/pcaudiolib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
