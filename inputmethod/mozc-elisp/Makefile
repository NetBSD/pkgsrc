# $NetBSD: Makefile,v 1.16 2016/03/05 11:28:42 jperkin Exp $
#

PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/mozc-/mozc-elisp-/}
PKGREVISION=	2
CATEGORIES=	inputmethod editors

EMACS_MODULES=	base leim

.include "../../editors/emacs/modules.mk"

INSTALLATION_DIRS=	${EMACS_LISPPREFIX} bin

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} build_mozc.py build -c Release ${_MAKE_JOBS} \
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

.include "../../inputmethod/mozc-server/Makefile.common"
