# $NetBSD: Makefile,v 1.1.1.1 2001/06/08 20:22:00 cjones Exp $
#

DISTNAME=	eieio-0.16
CATEGORIES=	lang editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cedet/}

MAINTAINER=	cjones@netbsd.org
HOMEPAGE=	http://cedet.sourceforge.net/eieio.shtml
COMMENT=	Enhanced Integration of Emacs Interpreted Objects

.include "../../mk/bsd.prefs.mk"

.if defined(USE_XEMACS)
DEPENDS+=	 	xemacs-*:../../editors/xemacs
EMACS=			xemacs
LISPDIR=		lib/xemacs/xemacs-packages/lisp/eieio
.else
DEPENDS+=	 	emacs-*:../../editors/emacs
EMACS=			emacs
LISPDIR=		share/emacs/site-lisp/eieio
.endif

BUILD_ENV+=	EMACS=${EMACS}
PLIST_SUBST+=	LISPDIR=${LISPDIR}

NO_CONFIGURE=	# set
USE_GMAKE=	# set

INFO_FILES=	eieio.info

SRCS=	eieio.el eieio-comp.el eieio-opt.el eieio-custom.el	\
	eieio-doc.el eieio-base.el compare-strings.el

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${LISPDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${PREFIX}/${LISPDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${INFO_FILES} ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
