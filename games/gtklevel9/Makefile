# $NetBSD: Makefile,v 1.59 2026/09/02 19:02:11 wiz Exp $

DISTNAME=		Level9_4.0_Source
PKGNAME=		gtklevel9-4.0
PKGREVISION=		50
CATEGORIES=		games
MASTER_SITES=		http://www.ifarchive.org/if-archive/level9/interpreters/level9/
EXTRACT_SUFX=		.zip
DIST_SUBDIR=		${PKGNAME_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.ifarchive.org/if-archive/level9/interpreters/level9/
COMMENT=		GTK+ port of the Level 9 text adventure interpreter

WRKSRC=			${WRKDIR}/Gtk

INSTALLATION_DIRS=	bin
BUILD_TARGET=		gtklevel9
USE_TOOLS+=		pkg-config

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/gtklevel9
	${INSTALL_DATA} ${WRKDIR}/level9.txt \
		${DESTDIR}${PREFIX}/share/doc/gtklevel9
	${INSTALL_PROGRAM} ${WRKSRC}/gtklevel9 ${DESTDIR}${PREFIX}/bin

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
