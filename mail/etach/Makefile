# $NetBSD: Makefile,v 1.6 2003/05/31 02:48:30 jschauma Exp $

DISTNAME=		etach-1.2.9
CATEGORIES=		mail
MASTER_SITES=		http://rulnick.com/etach/download/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://rulnick.com/etach/
COMMENT=		Emacs Lisp package for dealing with MIME email attachments

NO_CONFIGURE=		# defined
NO_BUILD=		# defined

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
	cd ${WRKSRC} && ${INSTALL_DATA} README.txt FAQ.txt LICENSE.txt	\
		${PREFIX}/share/doc/etach/

.include "../../mk/bsd.pkg.mk"
