# $NetBSD: Makefile,v 1.7 2000/08/04 13:09:16 martin Exp $
#

DISTNAME=		zenicb-19981202
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		thorpej@netbsd.org

MIRROR_DISTFILE=	no

# XXX YUCK!  I really don't like this, but what else are we going to do?
.include "../../mk/bsd.prefs.mk"
.if defined(USE_XEMACS)
EMACS=			xemacs
DEPENDS+=		xemacs-*:../../editors/xemacs
MAKEFLAGS+=		USE_XEMACS=${USE_XEMACS}
.else
EMACS=			emacs
DEPENDS+=		emacs-*:../../editors/emacs
.endif

ELISPDIR=		${PREFIX}/share/${EMACS}/site-lisp

PLIST_SUBST+=		EMACS=${EMACS}

pre-configure:
.if defined(USE_XEMACS)
	@${ECHO} "You have chosen Xemacs configuration."
.else
	@${ECHO} "To install for Xemacs, set the environment variable USE_XEMACS."
.endif

pre-install:
	${MKDIR} ${ELISPDIR}

do-build:

do-install:
	@for file in ${WRKSRC}/src/*.el; do \
		j="${INSTALL_DATA} $$file ${ELISPDIR}/"; \
		${ECHO} $$j; $$j; \
	done

.include "../../mk/bsd.pkg.mk"
