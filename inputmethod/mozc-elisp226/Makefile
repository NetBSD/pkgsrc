# $NetBSD: Makefile,v 1.7 2024/08/03 14:49:34 tsutsui Exp $

PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/mozc-/mozc-elisp-/}
PKGREVISION=	30
CATEGORIES=	inputmethod editors

EMACS_MODULES=	base leim

# Package Requires >= 24.3 for cl-lib etc.
EMACS_VERSIONS_ACCEPTED=	emacs26 emacs26nox
EMACS_VERSIONS_ACCEPTED+=	emacs27 emacs27nox
EMACS_VERSIONS_ACCEPTED+=	emacs28 emacs28nox
EMACS_VERSIONS_ACCEPTED+=	emacs29 emacs29nox

.include "../../editors/emacs/modules.mk"

INSTALLATION_DIRS=	${EMACS_LISPPREFIX} bin

pre-configure:
	${RM} ${WRKSRC}/unix/uim/uim.gyp

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} build_mozc.py build -c Release \
			unix/emacs/emacs.gyp:mozc_emacs_helper
	cd ${WRKSRC}/unix/emacs && \
		${EMACS_BIN} -q -batch -no-site-file -no-init-file \
			-f batch-byte-compile mozc.el

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out_${OSDEST}/Release/mozc_emacs_helper \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/unix/emacs/mozc.el \
		${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/unix/emacs/mozc.elc \
		${DESTDIR}${EMACS_LISPPREFIX}

.include "../../inputmethod/mozc-server226/Makefile.common"
.include "../../mk/bsd.pkg.mk"
