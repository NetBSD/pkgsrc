# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:48 jlam Exp $

DISTNAME=	sml-mode-3.9.5
CATEGORIES=	devel editors
MASTER_SITES=	ftp://flint.cs.yale.edu/pub/monnier/sml-mode/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Emacs mode for editing Standard ML source code

BUILD_TARGET=	default

INFO_FILES=	sml-mode.info

INSTALLATION_DIRS=	info

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/sml-mode
	cd ${WRKSRC} && ${INSTALL_DATA} *.el *.elc README NEWS TODO \
		ChangeLog ${EMACS_LISPPREFIX}/sml-mode
	${INSTALL_DATA} ${WRKSRC}/sml-mode.info ${PREFIX}/info

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
