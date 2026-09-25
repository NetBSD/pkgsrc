# $NetBSD: Makefile,v 1.17 2026/09/25 09:48:06 wiz Exp $

DISTNAME=	js2-20080406
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://js2-mode.googlecode.com/files/
EXTRACT_SUFX=	.el

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/js2-mode/
COMMENT=	Improved JavaScript mode for GNU Emacs

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
MESSAGE_SUBST+=	LISPDIR=${EMACS_LISPPREFIX:Q}

EMACS_VERSIONS_ACCEPTED+=	emacs31 emacs30 emacs29

do-build:
	cd ${WRKSRC} && ${EMACS_BIN} -batch -f batch-byte-compile ${DISTNAME}.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.el ${DESTDIR}${EMACS_LISPPREFIX}/js2.el
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.elc ${DESTDIR}${EMACS_LISPPREFIX}/js2.elc

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
