# $NetBSD: Makefile,v 1.2 2001/09/27 23:18:00 jlam Exp $
#

DISTNAME=       jde-2.2.7.1
CATEGORIES=     devel editors
MASTER_SITES=	${MASTER_SITE_LOCAL}
# The "real" site has silly naming conventions:
#MASTER_SITES=   http://jde.sunsite.dk/projects/jde/

MAINTAINER=     cjones@netbsd.org
HOMEPAGE=       http://jde.sunsite.dk/
COMMENT=        Full-featured Java editing mode for emacs

DEPENDS+=       speedbar-0.13a:../../editors/speedbar
DEPENDS+=       eieio-0.16:../../lang/eieio
DEPENDS+=       semantic-1.4beta5:../../devel/semantic
DEPENDS+=       elib-1.0:../../devel/elib

.include "../../mk/bsd.prefs.mk"

.if defined(USE_XEMACS)
DEPENDS+=               xemacs-[0-9]*:../../editors/xemacs
EMACS=                  xemacs
LISPDIR=                lib/xemacs/xemacs-packages/lisp/jde
.else
DEPENDS+=               emacs-[0-9]*:../../editors/emacs
EMACS=                  emacs
LISPDIR=                share/emacs/site-lisp/jde
.endif

BUILD_ENV+=     EMACS=${EMACS}
BUILD_ENV+=     LISPDIR=${LISPDIR}
PLIST_SUBST+=   LISPDIR=${LISPDIR}

NO_CONFIGURE=   # set
USE_JAVA=       yes

WRKSRC=         ${WRKDIR}/${DISTNAME}/lisp
MAKEFILE=       makefile

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${LISPDIR}
	cd ${WRKDIR}/${DISTNAME} ; tar cf - . | \
		( cd ${PREFIX}/${LISPDIR} ; tar xf - )

.include "../../mk/bsd.pkg.mk"
