# $NetBSD: Makefile,v 1.10 2020/11/05 22:34:33 nikita Exp $

DISTNAME=	v${VERSION}
VERSION=	20201010
PKGNAME=	${EMACS_PKGNAME_PREFIX}lua-mode-${VERSION}
CATEGORIES=	devel lua
MASTER_SITES=	https://github.com/immerrr/lua-mode/archive/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/immerrr/lua-mode/
COMMENT=	Emacs major mode for editing Lua code
LICENSE=	gnu-gpl-v2 # or newer

WRKSRC=			${WRKDIR}/lua-mode-${VERSION}

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
