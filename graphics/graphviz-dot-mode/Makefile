# $NetBSD: Makefile,v 1.5 2023/12/22 19:15:06 zafer Exp $

DISTNAME=	graphviz-dot-mode
PKGNAME=	${DISTNAME}-0.3.7
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	#
EXTRACT_SUFX=	.el

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/ppareit/graphviz-dot-mode/
COMMENT=	Graphviz dot mode for Emacs
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=	yes
USE_LANGUAGES=	# none
WRKSRC=		${WRKDIR}

EMACS_MODULES=	base

INSTALLATION_DIRS=	${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"

do-build:
	${EMACS_BIN} --no-init-file --no-site-file -batch \
		-f batch-byte-compile ${WRKSRC}/graphviz-dot-mode.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/graphviz-dot-mode.el ${WRKSRC}/graphviz-dot-mode.elc \
		${DESTDIR}${EMACS_LISPPREFIX}/

.include "../../mk/bsd.pkg.mk"
