# $NetBSD: Makefile,v 1.3 2008/10/11 09:31:55 uebayasi Exp $
#

DISTNAME=	cmake-mode
PKGNAME=	cmake-mode-20060923
CATEGORIES=	devel
MASTER_SITES=	http://www.cmake.org/CMakeDocs/
EXTRACT_SUFX=	.el

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cmake.org/
COMMENT=	Emacs mode for CMake syntax highlighting and indentation

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
MESSAGE_SUBST+=	LISPDIR=${EMACS_LISPPREFIX:Q}

do-build:
	cd ${WRKSRC} && ${EMACS_BIN} -batch -f batch-byte-compile cmake-mode.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/cmake-mode.* ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
