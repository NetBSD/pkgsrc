# $NetBSD: Makefile,v 1.9 2022/08/17 13:28:10 tnn Exp $
#

.include "../../devel/cmake/Makefile.common"

PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/cmake/cmake-mode/}
COMMENT=	Emacs mode for CMake syntax highlighting and indentation

USE_LANGUAGES=	# none
MESSAGE_SUBST+=	LISPDIR=${EMACS_LISPPREFIX:Q}

do-build:
	cd ${WRKSRC}/Auxiliary && ${EMACS_BIN} -batch -f batch-byte-compile cmake-mode.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/Auxiliary/cmake-mode.* ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
