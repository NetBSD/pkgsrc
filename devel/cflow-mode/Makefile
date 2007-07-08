# $NetBSD: Makefile,v 1.3 2007/07/08 12:35:10 wiz Exp $

DISTNAME=	cflow-1.1
PKGNAME=	cflow-mode-1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=cflow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/cflow/
COMMENT=	Emacs mode for GNU cflow output

.include "../../mk/emacs.mk"

do-build:
	${EMACS_BIN} --no-init-file -batch -f batch-byte-compile \
	${WRKSRC}/elisp/cflow-mode.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/elisp/cflow-mode.el ${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/elisp/cflow-mode.elc ${EMACS_LISPPREFIX}

.include "../../mk/bsd.pkg.mk"
