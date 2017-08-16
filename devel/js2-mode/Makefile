# $NetBSD: Makefile,v 1.9 2017/08/16 21:22:11 wiz Exp $
#

DISTNAME=	js2-20080406
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://js2-mode.googlecode.com/files/
EXTRACT_SUFX=	.el

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/js2-mode/
COMMENT=	Improved JavaScript mode for GNU Emacs

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
MESSAGE_SUBST+=	LISPDIR=${EMACS_LISPPREFIX:Q}

# no xemacs at all; emacs21 doesn't support full functionality
EMACS_VERSIONS_ACCEPTED=	emacs25 emacs24 emacs23 emacs22 emacs22nox

do-build:
	cd ${WRKSRC} && ${EMACS_BIN} -batch -f batch-byte-compile ${DISTNAME}.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.el ${DESTDIR}${EMACS_LISPPREFIX}/js2.el
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.elc ${DESTDIR}${EMACS_LISPPREFIX}/js2.elc

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
