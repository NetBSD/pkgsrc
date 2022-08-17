# $NetBSD: Makefile,v 1.13 2022/08/17 12:43:43 tnn Exp $

DISTNAME=	lua-mode-20210802
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=immerrr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/immerrr/lua-mode/
COMMENT=	Emacs major mode for editing Lua code
LICENSE=	gnu-gpl-v2 # or newer

USE_LANGUAGES=		# none
NO_CONFIGURE=		yes

INSTALLATION_DIRS=	${EMACS_LISPPREFIX}

EMACS_MODULES=		base

.include "../../editors/emacs/modules.mk"

do-build:
	${EMACS_BIN} --no-init-file --no-site-file -batch \
		-f batch-byte-compile ${WRKSRC}/lua-mode.el

do-install:
	cd ${WRKSRC} && \
	${INSTALL_DATA} lua-mode.el lua-mode.elc \
		${DESTDIR}${EMACS_LISPPREFIX}/

.include "../../mk/bsd.pkg.mk"
