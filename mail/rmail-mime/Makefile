# $NetBSD: Makefile,v 1.1.1.1 2002/11/27 03:29:48 jschauma Exp $
#

DISTNAME=	rmail-mime-1.13.0
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/semi/rmail-mime/

MAINTAINER=	jschauma@netbsd.org
COMMENT=	MIME-capabilities for RMAIL in Emacs

DEPENDS=	semi>=1.14.4:../../devel/semi

.include "../../mk/bsd.prefs.mk"

.if defined(USE_XEMACS)
DEPENDS+=	xemacs-[0-9]*:../../editors/xemacs
EMACS=		xemacs
SITE_LISP=	lib/xemacs/xemacs-packages/lisp/
.else
DEPENDS+=	emacs-[0-9]*:../../editors/emacs
EMACS=		emacs
SITE_LISP=	share/emacs/site-lisp
.endif

PLIST_SUBST+=	SITE_LISP=${SITE_LISP}

do-build:
	cd ${WRKSRC}; ${EMACS} --no-init-file --no-site-file -batch \
		-l ruby-mode.el -f batch-byte-compile rmail-mime.el

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${SITE_LISP}
	${INSTALL_DATA} ${WRKSRC}/rmail-mime.el ${PREFIX}/${SITE_LISP}
	${INSTALL_DATA} ${WRKSRC}/rmail-mime.elc ${PREFIX}/${SITE_LISP}

.include "../../mk/bsd.pkg.mk"
