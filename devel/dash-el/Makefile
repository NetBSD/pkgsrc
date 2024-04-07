# $NetBSD: Makefile,v 1.1 2024/04/07 18:56:40 ryoon Exp $

DISTNAME=	dash.el-2.19.1
PKGNAME=	${DISTNAME:C/\.el/-el/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=magnars/}
GITHUB_PROJECT=	dash.el
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/magnars/dash.el
COMMENT=	Modern list api for Emacs. No 'cl required
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=	${EMACS_LISPPREFIX}/dash

do-build:
	${EMACS_BIN} --no-init-file --no-site-file -batch \
		-f batch-byte-compile ${WRKSRC}/dash.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/dash.el \
		${DESTDIR}${EMACS_LISPPREFIX}/dash
	${INSTALL_DATA} ${WRKSRC}/dash.elc \
		${DESTDIR}${EMACS_LISPPREFIX}/dash

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
