# $NetBSD: Makefile,v 1.1 2022/04/15 09:48:19 nikita Exp $

DISTNAME=	emacs-neotree-0.5.2.98fe213
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jaypei/}
GITHUB_TAG=	98fe21334affaffe2334bf7c987edaf1980d2d0b

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaypei/emacs-neotree/
COMMENT=	Tree explorer plugin for Emacs
LICENSE=	gnu-gpl-v3

NO_CONFIGURE=	yes

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
