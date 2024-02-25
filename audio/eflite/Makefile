# $NetBSD: Makefile,v 1.1 2024/02/25 22:00:09 wiz Exp $

COMMITS=	86
DISTNAME=	eflite-0.0.0.${COMMITS}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=mgorse/}
GITHUB_TAG=	21b950b64c268626351f98625fa1344b37881f1a

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mgorse/eflite
COMMENT=	Speech server for screen readers using Festival Lite
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c
USE_TOOLS=		gmake autoconf automake autoreconf
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	CFLAGS="${CFLAGS} -DDO_WAVE_CANCEL"
CONFIGURE_ARGS+=	LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	DESTDIR="${DESTDIR}"

BUILD_TARGET=		eflite

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fi

.include "../../audio/flite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
