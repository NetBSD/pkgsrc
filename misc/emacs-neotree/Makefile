# $NetBSD: Makefile,v 1.3 2026/09/25 09:48:11 wiz Exp $

DISTNAME=	emacs-neotree-0.5.2.98fe213
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/emacs-//}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jaypei/}
GITHUB_PROJECT=	emacs-neotree
GITHUB_TAG=	98fe21334affaffe2334bf7c987edaf1980d2d0b

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaypei/emacs-neotree/
COMMENT=	Tree explorer plugin for Emacs
LICENSE=	gnu-gpl-v3

NO_CONFIGURE=	yes

EMACS_VERSIONS_INCOMPATIBLE=	emacs20 xemacs214 xemacs215 xemacs214nox xemacs215nox

do-build:
	cd ${WRKSRC} && ${EMACS_BIN} -batch -f batch-byte-compile neotree.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/neotree
	${INSTALL_DATA} ${WRKSRC}/neotree.e* \
		${DESTDIR}${EMACS_LISPPREFIX}/neotree
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/neotree/icons
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm \
		${DESTDIR}${EMACS_LISPPREFIX}/neotree/icons

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
