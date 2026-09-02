# $NetBSD: Makefile,v 1.96 2026/09/02 19:03:27 wiz Exp $

DISTNAME=		gperiodic-2.0.10
PKGREVISION=		44
CATEGORIES=		misc x11
#MASTER_SITES=		http://www.frantz.fi/software/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.frantz.fi/software/gperiodic.php
COMMENT=		Displays a periodic table of the elements
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt pkg-config

BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGDK_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGDK_PIXBUF_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

MAKE_FLAGS+=		bindir=${PREFIX}/bin
MAKE_FLAGS+=		datadir=${PREFIX}/share
MAKE_FLAGS+=		LOCALEDIR=${PREFIX}/${PKGLOCALEDIR}/locale
BUILD_TARGET=		gperiodic

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
