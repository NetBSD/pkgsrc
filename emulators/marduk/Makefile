# $NetBSD: Makefile,v 1.6 2023/11/14 14:01:47 wiz Exp $

# The author has not yet created any tags, but this is what it reports
# as its version.
MARDUK_VERSION=	0.26e

DISTNAME=	marduk-${MARDUK_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=buricco/}
GITHUB_TAG=	7cf954b7f9681daafa7240f49b7860f6f2107898

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://github.com/buricco/marduk
COMMENT=	Portable emulator of the NABU Personal Computer
LICENSE=	mit

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c99

LDFLAGS.SunOS+=	-lsocket

MARDUK_ROMDIR=	share/marduk

INSTALLATION_DIRS=	bin ${MARDUK_ROMDIR}

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=	-DROM_PATHSPEC="\"${PREFIX}/${MARDUK_ROMDIR}\""
CFLAGS+=	${CPPFLAGS}	# Makefile ignores CPPFLAGS

do-build:
	cd ${WRKSRC} && ${MAKE} CFLAGS=${CFLAGS:Q} LDFLAGS=${LDFLAGS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/marduk ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/opennabu.bin \
	    ${DESTDIR}${PREFIX}/${MARDUK_ROMDIR}

.if ${OPSYS} != "Darwin"
.include "../../x11/gtk3/buildlink3.mk"
.endif

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
