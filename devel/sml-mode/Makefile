# $NetBSD: Makefile,v 1.18 2012/10/31 11:19:46 asau Exp $

DISTNAME=	sml-mode-3.9.5
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel editors
MASTER_SITES=	ftp://flint.cs.yale.edu/pub/monnier/sml-mode/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Emacs mode for editing Standard ML source code

BUILD_TARGET=	default

INFO_FILES=	# PLIST

INSTALLATION_DIRS=	${EMACS_INFOPREFIX} ${EMACS_LISPPREFIX}/sml-mode

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} *.el *.elc README NEWS TODO \
		ChangeLog ${DESTDIR}${EMACS_LISPPREFIX}/sml-mode
	${INSTALL_DATA} ${WRKSRC}/sml-mode.info ${DESTDIR}${EMACS_INFOPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
