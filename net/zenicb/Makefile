#	$NetBSD: Makefile,v 1.1.1.1 1998/12/09 06:18:21 thorpej Exp $

DISTNAME=		zenicb-19981202
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		thorpej@netbsd.org

MIRROR_DISTFILE=	no

# XXX YUCK!  I really don't like this, but what else are we going to do?
.include "../../mk/bsd.prefs.mk"
.if defined(USE_XEMACS)
EMACS=			xemacs
RUN_DEPENDS+=		xemacs-20.4:../../editors/xemacs20
.else
EMACS=			emacs
RUN_DEPENDS+=		emacs-20.3:../../editors/emacs
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
		echo $$j; $$j; \
	done

.include "../../mk/bsd.pkg.mk"
