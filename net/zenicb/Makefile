# $NetBSD: Makefile,v 1.5 1999/08/30 09:06:44 jlam Exp $
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
DEPENDS+=		xemacs-21.1.6:../../editors/xemacs
.else
EMACS=			emacs
DEPENDS+=		emacs-20.3:../../editors/emacs
.endif

ELISPDIR=		${PREFIX}/share/${EMACS}/site-lisp

PLIST_SRC=		${WRKDIR}/PLIST.tmp

pre-configure:
	@${ECHO} "To install for Xemacs, set the environment variable USE_XEMACS."

pre-install:
	${SED} -e "s/@EMACS@/${EMACS}/g" ${PKGDIR}/PLIST > ${PLIST_SRC}

do-build:

do-install:
	@for file in ${WRKSRC}/src/*.el; do \
		j="${INSTALL_DATA} $$file ${ELISPDIR}/"; \
		${ECHO} $$j; $$j; \
	done

.include "../../mk/bsd.pkg.mk"
