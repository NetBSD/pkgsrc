# $NetBSD: Makefile,v 1.3 2013/02/17 19:18:03 dholland Exp $

DISTNAME=	graphviz-dot-mode
PKGNAME=	${DISTNAME}-0.3.7
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://users.skynet.be/ppareit/projects/graphviz-dot-mode/
EXTRACT_SUFX=	.el

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://users.skynet.be/ppareit/projects/graphviz-dot-mode/graphviz-dot-mode.html
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
