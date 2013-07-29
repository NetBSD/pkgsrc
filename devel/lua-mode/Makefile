# $NetBSD: Makefile,v 1.8 2013/07/29 20:35:00 wiz Exp $

DISTNAME=	rel-${VERSION}
VERSION=	20130419
PKGNAME=	${EMACS_PKGNAME_PREFIX}lua-mode-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/immerrr/lua-mode/archive/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/immerrr/lua-mode/
COMMENT=	Emacs major mode for editing Lua code
LICENSE=	gnu-gpl-v2 # or newer

WRKSRC=			${WRKDIR}/lua-mode-rel-${VERSION}

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
