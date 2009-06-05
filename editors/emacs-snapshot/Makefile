# $NetBSD: Makefile,v 1.1.1.1 2009/06/05 02:57:53 minskim Exp $

DISTNAME=	emacs-snapshot_20090604.orig
PKGNAME=	${DISTNAME:S/snapshot_/${EMACS_VERSION}./:S/.orig//}
CATEGORIES=	editors
MASTER_SITES=	http://emacs.orebokech.com/pool/main/e/emacs-snapshot/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (development version)
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	emacs-nox11-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs/files
GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_DIRS+=	xdg-1.1
USE_TOOLS+=	gmake makeinfo gzip
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:C/\.[0-9]*$//}

CONFIGURE_ARGS+=	--srcdir=${WRKSRC}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ENV+=		GAMEOWN=${GAMEOWN}

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		GAMEDATAMODE
PLIST_SRC+=		PLIST

BUILD_TARGET=		bootstrap
EMACS_VERSION=		23.0.94
PLIST_SUBST+=		EMACS_VERSION=${EMACS_VERSION}

REPLACE_PERL=		lib-src/grep-changelog
CHECK_INTERPRETER_SKIP=	bin/grep-changelog

MAKE_DIRS_PERMS+=	${VARBASE}/games/emacs ${GAMEOWN} ${GAMEGRP} ${GAMEDIRMODE}
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/emacs/snake-scores \
			${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/emacs/tetris-scores \
			${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}

# build PATH in the dumped emacs is not a problem
CHECK_WRKREF_SKIP+=	bin/emacs
CHECK_WRKREF_SKIP+=	bin/emacs-${EMACS_VERSION}

.include "options.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/oss.buildlink3.mk"

post-extract:
	cp ${FILESDIR}/site-init.el ${WRKSRC}/lisp

.include "../../mk/bsd.pkg.mk"
