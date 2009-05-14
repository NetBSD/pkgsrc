# $NetBSD: Makefile,v 1.1.1.1 2009/05/14 06:09:13 minskim Exp $

DISTNAME=	markdown-mode
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}-1.6
CATEGORIES=	textproc
MASTER_SITES=	http://jblevins.org/projects/markdown-mode/
EXTRACT_SUFX=	.el

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://jblevins.org/projects/markdown-mode/
COMMENT=	Emacs major mode for editing Markdown-formatted text files

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	${EMACS_LISPPREFIX}

EMACS_MODULES=	base

.include "../../editors/emacs/modules.mk"

do-build:
	${EMACS_BIN} --no-init-file --no-site-file -batch \
		-f batch-byte-compile ${WRKSRC}/markdown-mode.el

do-install:
	cd ${WRKSRC} && \
	${INSTALL_DATA} markdown-mode.el markdown-mode.elc \
		${DESTDIR}${EMACS_LISPPREFIX}/

.include "../../mk/bsd.pkg.mk"
