# $NetBSD: Makefile,v 1.4 2001/09/27 23:17:49 jlam Exp $
#

DISTNAME=		zenicb-19981202
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		thorpej@netbsd.org
COMMENT=		ICB client for Emacs

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

# XXX YUCK!  I really don't like this, but what else are we going to do?
.include "../../mk/bsd.prefs.mk"
.if defined(USE_XEMACS)
EMACS=			xemacs
DEPENDS+=		xemacs-[1-9]*:../../editors/xemacs
MAKEFLAGS+=		USE_XEMACS=${USE_XEMACS}
ELISPDIR=		lib/xemacs/xemacs-packages/lisp
.else
EMACS=			emacs
DEPENDS+=		emacs-[0-9]*:../../editors/emacs
ELISPDIR=		share/emacs/site-lisp
.endif

PLIST_SUBST+=		ELISPDIR=${ELISPDIR}

pre-configure:
.if defined(USE_XEMACS)
	@${ECHO} "You have chosen Xemacs configuration."
.else
	@${ECHO} "To install for Xemacs, set the environment variable USE_XEMACS."
.endif

do-build:

do-install:
.if defined(USE_XEMACS)
	@${INSTALL_DATA_DIR} ${PREFIX}/${ELISPDIR}
.endif
	@for file in ${WRKSRC}/src/*.el; do \
		j="${INSTALL_DATA} $$file ${PREFIX}/${ELISPDIR}/"; \
		${ECHO} $$j; $$j; \
	done

.include "../../mk/bsd.pkg.mk"
