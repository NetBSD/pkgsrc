# $NetBSD: Makefile,v 1.12 2005/06/16 06:57:49 jlam Exp $
#

DISTNAME=	speedbar-0.14beta4
PKGNAME=	speedbar-0.14rc4
CATEGORIES=	editors devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cedet/}

MAINTAINER=	cjones@NetBSD.org
HOMEPAGE=	http://cedet.sourceforge.net/speedbar.shtml
COMMENT=	Directory and code browser for emacs

.include "../../mk/emacs.mk"

BUILD_ENV+=	EMACS=${EMACS}

NO_CONFIGURE=	# set
USE_TOOLS+=	gmake

INFO_FILES=	speedbar.info

SRCS=	speedbar.el dframe.el
# XXX cd ${WRKSRC}; ${MAKE} -V opt_IMAGES
IMAGES=	sb-dir-plus.xpm sb-dir-minus.xpm sb-dir.xpm sb-pg-plus.xpm 	\
	sb-pg-minus.xpm sb-pg.xpm sb-mail.xpm sb-tag-plus.xpm 		\
	sb-tag-minus.xpm sb-tag.xpm sb-tag-gt.xpm sb-tag-v.xpm 		\
	sb-tag-type.xpm sb-image.el sb-obj.xpm sb-chk.xpm sb-objod.xpm 	\
	sb-label.xpm sb-ro.xpm sb-doc.xpm sb-info.xpm sb-doc-plus.xpm 	\
	sb-doc-minus.xpm sb-box.xpm sb-box-plus.xpm sb-box-minus.xpm

INSTALLATION_DIRS=	info

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/speedbar
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${EMACS_LISPPREFIX}/speedbar
	cd ${WRKSRC} && ${INSTALL_DATA} ${IMAGES} ${EMACS_LISPPREFIX}/speedbar
	cd ${WRKSRC} && ${INSTALL_DATA} ${INFO_FILES} ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
