# $NetBSD: Makefile,v 1.1.1.1 2007/02/24 20:47:25 wiz Exp $
#

DISTNAME=	cmake-mode
PKGNAME=	cmake-mode-20060923
CATEGORIES=	devel
MASTER_SITES=	http://www.cmake.org/CMakeDocs/
EXTRACT_SUFX=	.el

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cmake.org/
COMMENT=	Emacs mode for CMake syntax highlighting and indentation

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
MESSAGE_SUBST+=	LISPDIR=${EMACS_LISPPREFIX:Q}

do-build:
	cd ${WRKSRC} && ${EMACS_BIN} -batch -f batch-byte-compile cmake-mode.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/cmake-mode.* ${EMACS_LISPPREFIX}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
