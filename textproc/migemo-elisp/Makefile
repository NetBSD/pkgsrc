# $NetBSD: Makefile,v 1.8 2016/03/13 09:36:59 taca Exp $

.include "../../textproc/migemo/Makefile.common"

PKGNAME=	${EMACS_PKGNAME_PREFIX}migemo-elisp-${MIGEMO_VERSION}
PKGREVISION=	5

COMMENT=	Elisp for migemo

DEPENDS+=	${RUBY_PKGPREFIX}-migemo>=${MIGEMO_VERSION}:../../textproc/migemo

.include "../../editors/emacs/modules.mk"
.if defined(EMACS_FLAVOR) && ${EMACS_FLAVOR} == "xemacs"
DEPENDS+=	xemacs-packages-[0-9]*:../../editors/xemacs-packages
.endif

do-configure:
	sed -e "s!@pkgdatadir@!${PREFIX}/share/migemo!g" -e "s!ruby!${RUBY}!" ${WRKSRC}/migemo.el.in > ${WRKSRC}/migemo.el

do-build:
	${ECHO} "(setq load-path (cons nil load-path))" > ${WRKSRC}/script
	${EMACS_BIN} -q -batch -l ${WRKSRC}/script -f batch-byte-compile ${WRKSRC}/migemo.el
	rm ${WRKSRC}/script

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/migemo.el ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/migemo.elc ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
