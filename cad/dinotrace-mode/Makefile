# $NetBSD: Makefile,v 1.4 2005/11/18 03:58:54 dmcmahill Exp $
#

DISTNAME=	dinotrace-9.3a
PKGNAME=	${EMACS_PKGNAME_PREFIX}dinotrace-mode-9.3a
CATEGORIES=	cad editors
MASTER_SITES=	http://www.veripool.com/ftp/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE= 	http://www.veripool.com/dinotrace/
COMMENT=	Emacs major mode for dinotrace

DEPENDS+=	${EMACS_PKGNAME_PREFIX}verilog-mode>=3.13:../../cad/verilog-mode

.include "../../mk/bsd.prefs.mk"

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
EMACS=	emacs
.else
EMACS=	xemacs
.endif

SRCS=	dinotrace.el sim-log.el

do-build:
	for f in ${SRCS}; do						\
		${EMACS} --no-init-file --no-site-file -batch		\
		-f batch-byte-compile ${WRKSRC}/lisp/$$f;			\
	done

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/${PKGBASE}
	cd ${WRKSRC}/lisp && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} ${EMACS_LISPPREFIX}/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
