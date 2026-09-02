# $NetBSD: Makefile,v 1.57 2026/09/02 19:01:50 wiz Exp $
#

DISTNAME=	scite339
PKGNAME=	scite-3.3.9
PKGREVISION=	28
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scintilla/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://scintilla.sourceforge.net/
COMMENT=	Source code editor
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=			${WRKDIR}/scite
USE_LANGUAGES=		c c++
BUILD_DIRS+=		gtk
USE_TOOLS+=		gmake pkg-config
MAKE_FILE=		makefile
INSTALLATION_DIRS=	share/applications share/pixmaps

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=lua.vers

post-extract:
	${RM} -r ${WRKDIR}/scintilla
	${RM} ${WRKSRC}/gtk/deps.mak
	${TOUCH} ${WRKSRC}/gtk/deps.mak

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.scintilla+= scintilla>=3.2.4
.include "../../devel/scintilla/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
