# $NetBSD: Makefile,v 1.21 2012/10/02 20:11:38 asau Exp $
#

DISTNAME=	eieio-0.17
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	3
CATEGORIES=	lang editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cedet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cedet.sourceforge.net/eieio.shtml
COMMENT=	Enhanced Integration of Emacs Interpreted Objects

EMACS_VERSIONS_ACCEPTED= \
	emacs20 emacs21 emacs21nox emacs22 emacs22nox \
	xemacs214 xemacs214nox xemacs215 xemacs215nox

EMACS_MODULES+=	base
MAKEFLAGS+=	EMACS=${EMACS_BIN:Q}

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
INFO_FILES=	# PLIST

# XXX $cd ${WRKSRC}; ${MAKE} -V eieio_LISP
SRCS=	eieio.el eieio-comp.el eieio-opt.el eieio-custom.el eieio-doc.el \
	eieio-base.el
# XXX $cd ${WRKSRC}; ${MAKE} -V examples_LISP
SRCS+=	tree.el call-tree.el chart.el eieio-speedbar.el linemark.el

INSTALLATION_DIRS=	${EMACS_INFOPREFIX}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/eieio
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${DESTDIR}${EMACS_LISPPREFIX}/eieio
	cd ${WRKSRC}; for f in *.info *.info-[0-9]*; do			\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${EMACS_INFOPREFIX};	\
	done

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
