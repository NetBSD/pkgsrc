# $NetBSD: Makefile,v 1.22 2012/10/03 11:43:43 asau Exp $
#

DISTNAME=	speedbar-0.14beta4
PKGNAME=	${EMACS_PKGNAME_PREFIX}speedbar-0.14rc4
PKGREVISION=	3
CATEGORIES=	editors devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cedet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cedet.sourceforge.net/speedbar.shtml
COMMENT=	Directory and code browser for emacs

.include "../../editors/emacs/modules.mk"

PKGSRC_MAKE_ENV+=	EMACS=${EMACS}

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
INFO_FILES=	# PLIST

SRCS=	speedbar.el dframe.el
# XXX cd ${WRKSRC}; ${MAKE} -V opt_IMAGES
IMAGES=	sb-dir-plus.xpm sb-dir-minus.xpm sb-dir.xpm sb-pg-plus.xpm 	\
	sb-pg-minus.xpm sb-pg.xpm sb-mail.xpm sb-tag-plus.xpm 		\
	sb-tag-minus.xpm sb-tag.xpm sb-tag-gt.xpm sb-tag-v.xpm 		\
	sb-tag-type.xpm sb-image.el sb-obj.xpm sb-chk.xpm sb-objod.xpm 	\
	sb-label.xpm sb-ro.xpm sb-doc.xpm sb-info.xpm sb-doc-plus.xpm 	\
	sb-doc-minus.xpm sb-box.xpm sb-box-plus.xpm sb-box-minus.xpm

INSTALLATION_DIRS=	${EMACS_INFOPREFIX}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/speedbar
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${DESTDIR}${EMACS_LISPPREFIX}/speedbar
	cd ${WRKSRC} && ${INSTALL_DATA} ${IMAGES}			\
			${DESTDIR}${EMACS_LISPPREFIX}/speedbar
	cd ${WRKSRC}; for file in *.info *.info-[0-9]*; do		\
		${TEST} ! -f "$$file" ||				\
		${INSTALL_DATA} "$$file" ${DESTDIR}${EMACS_INFOPREFIX};	\
	done

.include "../../mk/bsd.pkg.mk"
