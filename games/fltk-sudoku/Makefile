# $NetBSD: Makefile,v 1.17 2019/10/21 10:04:12 micha Exp $

DISTNAME=	fltk-1.3.5-source
PKGNAME=	${DISTNAME:S/fltk-/fltk-sudoku-/:S/-source//}
VERS=		{DISTNAME:S/fltk-//:S/-source//}
CATEGORIES=	games x11
MASTER_SITES=	https://fltk.org/pub/fltk/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
# This is one of the example programs shipped with the FLTK library
HOMEPAGE=	https://www.fltk.org/
COMMENT=	FLTK example Sudoku game creator and solver
LICENSE=	gnu-lgpl-v2

WRKSRC=			${WRKDIR}/${DISTNAME:S/-source//}
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"

PTHREAD_OPTS+=		require
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	ac_cv_have_overlay=yes

CONFIGURE_ARGS+=	--disable-shared
# Use pkgsrc versions, not package's bundled versions.
CONFIGURE_ARGS+=	--disable-localjpeg --disable-localzlib --disable-localpng

INSTALLATION_DIRS=	bin

USE_GAMESGROUP=		yes
SPECIAL_PERMS=		bin/fltk-sudoku ${SETGID_GAMES_PERMS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/test/sudoku ${DESTDIR}${PREFIX}/bin/fltk-sudoku

.if ${OPSYS} != "Darwin"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXft/buildlink3.mk"
.  include "../../x11/libXinerama/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.  include "../../x11/libXt/buildlink3.mk"
.endif
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
