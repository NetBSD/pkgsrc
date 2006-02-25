# $NetBSD: Makefile,v 1.1.1.1 2006/02/25 21:43:26 rpaulo Exp $

DISTNAME=	cflow-1.0
PKGNAME=	cflow-mode-1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=cflow/}

MAINTAINER=	rpaulo@NetBSD.org
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
