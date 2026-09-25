# $NetBSD: Makefile,v 1.23 2026/09/25 09:48:07 wiz Exp $

DISTNAME=	sml-mode-3.9.5
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel editors
MASTER_SITES=	# ftp://flint.cs.yale.edu/pub/monnier/sml-mode/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Emacs mode for editing Standard ML source code

BUILD_TARGET=	default

MAKE_FLAGS+=	EMACS=${EMACS_BIN}

INFO_FILES=	yes

INSTALLATION_DIRS=	${EMACS_INFOPREFIX} ${EMACS_LISPPREFIX}/sml-mode

EMACS_VERSIONS_INCOMPATIBLE=	xemacs214 xemacs215 xemacs214nox xemacs215nox

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} *.el *.elc README NEWS TODO \
		ChangeLog ${DESTDIR}${EMACS_LISPPREFIX}/sml-mode
	${INSTALL_DATA} ${WRKSRC}/sml-mode.info ${DESTDIR}${EMACS_INFOPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
