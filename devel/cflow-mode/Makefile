# $NetBSD: Makefile,v 1.7 2012/10/31 11:16:45 asau Exp $

DISTNAME=	cflow-1.1
PKGNAME=	cflow-mode-1.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=cflow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/cflow/
COMMENT=	Emacs mode for GNU cflow output

.include "../../editors/emacs/modules.mk"

do-build:
	${EMACS_BIN} --no-init-file -batch -f batch-byte-compile \
	${WRKSRC}/elisp/cflow-mode.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/elisp/cflow-mode.el \
		${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/elisp/cflow-mode.elc \
		${DESTDIR}${EMACS_LISPPREFIX}

.include "../../mk/bsd.pkg.mk"
