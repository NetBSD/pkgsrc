# $NetBSD: Makefile,v 1.11 2022/05/14 22:25:33 dholland Exp $

DISTNAME=	cflow-1.6
PKGNAME=	cflow-mode-1.6
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=cflow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/cflow/
COMMENT=	Emacs mode for GNU cflow output
LICENSE=	gnu-gpl-v3

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
