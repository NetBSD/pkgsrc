# $NetBSD: Makefile,v 1.12 2026/09/25 09:48:12 wiz Exp $

DISTNAME=	markdown-mode-2.4
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jrblevin/}
GITHUB_PROJECT=	markdown-mode
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://jblevins.org/projects/markdown-mode/
COMMENT=	Emacs major mode for editing Markdown-formatted text files
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	${EMACS_LISPPREFIX}

EMACS_MODULES=	base

EMACS_VERSIONS_INCOMPATIBLE=	emacs20 xemacs214 xemacs215 xemacs214nox xemacs215nox

.include "../../editors/emacs/modules.mk"

do-build:
	${EMACS_BIN} --no-init-file --no-site-file -batch \
		-f batch-byte-compile ${WRKSRC}/markdown-mode.el

do-install:
	cd ${WRKSRC} && \
	${INSTALL_DATA} markdown-mode.el markdown-mode.elc \
		${DESTDIR}${EMACS_LISPPREFIX}/

.include "../../mk/bsd.pkg.mk"
