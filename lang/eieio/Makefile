# $NetBSD: Makefile,v 1.11 2005/06/16 06:58:00 jlam Exp $
#

DISTNAME=	eieio-0.17
CATEGORIES=	lang editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cedet/}

MAINTAINER=	cjones@NetBSD.org
HOMEPAGE=	http://cedet.sourceforge.net/eieio.shtml
COMMENT=	Enhanced Integration of Emacs Interpreted Objects

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
.elif ${EMACS_FLAVOR} == "xemacs"
DEPENDS+=	xemacs-packages:../../editors/xemacs-packages
.endif

MAKEFLAGS+=	EMACS=${EMACS_BIN}

NO_CONFIGURE=	# set
USE_TOOLS+=	gmake

INFO_FILES=	eieio.info

# XXX $cd ${WRKSRC}; ${MAKE} -V eieio_LISP
SRCS=	eieio.el eieio-comp.el eieio-opt.el eieio-custom.el eieio-doc.el \
	eieio-base.el
# XXX $cd ${WRKSRC}; ${MAKE} -V examples_LISP
SRCS+=	tree.el call-tree.el chart.el eieio-speedbar.el linemark.el

INSTALLATION_DIRS=	${INFO_DIR}

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/eieio
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${EMACS_LISPPREFIX}/eieio
	cd ${WRKSRC} && ${INSTALL_DATA} ${INFO_FILES} ${PREFIX}/${INFO_DIR}

.include "../../mk/bsd.pkg.mk"
