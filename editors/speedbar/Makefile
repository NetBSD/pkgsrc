# $NetBSD: Makefile,v 1.4 2002/02/18 15:14:17 seb Exp $
#

DISTNAME=	speedbar-0.13a
CATEGORIES=	editors devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cedet/}

MAINTAINER=	cjones@netbsd.org
HOMEPAGE=	http://cedet.sourceforge.net/speedbar.shtml
COMMENT=	Directory and code browser for emacs

.include "../../mk/bsd.prefs.mk"

.if defined(USE_XEMACS)
DEPENDS+=	 	xemacs-[0-9]*:../../editors/xemacs
EMACS=			xemacs
LISPDIR=		lib/xemacs/xemacs-packages/lisp/speedbar
.else
DEPENDS+=	 	emacs-[0-9]*:../../editors/emacs
EMACS=			emacs
LISPDIR=		share/emacs/site-lisp/speedbar
.endif

BUILD_ENV+=	EMACS=${EMACS}
PLIST_SUBST+=	LISPDIR=${LISPDIR}

NO_CONFIGURE=	# set
USE_GMAKE=	# set

INFO_FILES=	speedbar.info

SRCS=	speedbar.el dframe.el
IMAGES=	sb-dir-plus.xpm sb-dir-minus.xpm sb-dir.xpm sb-pg-plus.xpm	\
	sb-pg-minus.xpm sb-pg.xpm sb-mail.xpm sb-tag-plus.xpm		\
	sb-tag-minus.xpm sb-tag.xpm sb-tag-gt.xpm sb-tag-v.xpm		\
	sb-tag-type.xpm sb-image.el

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${LISPDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${PREFIX}/${LISPDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${IMAGES} ${PREFIX}/${LISPDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${INFO_FILES} ${PREFIX}/info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
