# $NetBSD: Makefile,v 1.14 2006/03/31 05:37:09 jlam Exp $

DISTNAME=	sml-mode-3.9.5
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel editors
MASTER_SITES=	ftp://flint.cs.yale.edu/pub/monnier/sml-mode/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Emacs mode for editing Standard ML source code

BUILD_TARGET=	default

INFO_FILES=	# PLIST

INSTALLATION_DIRS=	${EMACS_INFOPREFIX} ${EMACS_LISPPREFIX}/sml-mode

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} *.el *.elc README NEWS TODO \
		ChangeLog ${EMACS_LISPPREFIX}/sml-mode
	${INSTALL_DATA} ${WRKSRC}/sml-mode.info ${EMACS_INFOPREFIX}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
