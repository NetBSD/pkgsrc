# $NetBSD: Makefile,v 1.2 2001/02/17 18:24:44 wiz Exp $

DISTNAME=		etach-1.1.6
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=etach/}

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://etach.sourceforge.net
COMMENT=		Emacs Lisp package for dealing with MIME email attachments

NO_CONFIGURE=		YES
NO_BUILD=		YES

.include "../../mk/bsd.prefs.mk"

.if defined(USE_XEMACS)
DEPENDS+=		xemacs-[0-9]*:../../editors/xemacs
LISPDIR=		lib/xemacs/xemacs-packages/lisp/mail-lib
.else
DEPENDS+=		emacs-[0-9]*:../../editors/emacs
LISPDIR=		share/emacs/site-lisp
.endif

PLIST_SUBST+=		LISPDIR=${LISPDIR}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/etach.el ${PREFIX}/${LISPDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/etach
	@for t in ${WRKSRC}/README.txt ${WRKSRC}/FAQ.txt \
	${WRKSRC}/LICENSE.txt; do \
		c="${INSTALL_DATA} $$t ${PREFIX}/share/doc/etach/"; \
		${ECHO} $$c; $$c; \
	done

.include "../../mk/bsd.pkg.mk"
