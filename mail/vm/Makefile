# $NetBSD: Makefile,v 1.5 2001/04/14 21:43:49 jtb Exp $

DISTNAME=	vm-6.92
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.uni-mainz.de/pub/gnu/vm/ \
		ftp://tug.org/vm/ \
		ftp://ftp.uu.net/networking/mail/vm/ \
		ftp://psg.com/pub/vm/ \
		ftp://sunsite.cnlab-switch.ch/mirror/vm/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.wonderworks.com/vm/
COMMENT=	VM (View Mail) is an advanced mail user agent for Emacs

.include "../../mk/bsd.prefs.mk"

.if defined(USE_XEMACS)
DEPENDS+=	xemacs>=19.14:../../editors/xemacs
MAKE_ENV+=	EMACS=xemacs
MAKE_ENV+=	LISPDIR="${PREFIX}/lib/xemacs/xemacs-packages/lisp/vm"
MAKE_ENV+=	INFODIR="${PREFIX}/lib/xemacs/xemacs-packages/info"
MAKE_ENV+=	PIXMAPDIR="${PREFIX}/lib/xemacs/xemacs-packages/etc/vm"
MAKE_ENV+=	BINDIR="${PREFIX}/bin"
PLIST_SRC=	${PKGDIR}/PLIST.xemacs
.else
DEPENDS+=	emacs>=19.34:../../editors/emacs
MAKE_ENV+=	EMACS=emacs
MAKE_ENV+=	LISPDIR="${PREFIX}/share/emacs/site-lisp/vm"
MAKE_ENV+=	INFODIR="${PREFIX}/info"
MAKE_ENV+=	PIXMAPDIR="${PREFIX}/share/emacs/site-lisp/vm/pixmaps"
MAKE_ENV+=	BINDIR="${PREFIX}/bin"
INFO_FILES=	vm.info
PLIST_SRC=	${PKGDIR}/PLIST.emacs
.endif

do-install:
	${INSTALL_DATA_DIR} ${LISPDIR}
	@for f in ${WRKSRC}/*.el ${WRKSRC}/*.elc; do			\
		i="${INSTALL_DATA} $$f ${LISPDIR}";			\
		${ECHO} $$i; $$i;					\
	done
	@for f in ${WRKSRC}/*.info*; do					\
		i="${INSTALL_DATA} $$f ${INFODIR}";			\
		${ECHO} $$i; $$i;					\
	done
	${INSTALL_DATA_DIR} ${PIXMAPDIR}
	@for f in ${WRKSRC}/pixmaps/*.x[pb]m; do			\
		i="${INSTALL_DATA} $$f ${PIXMAPDIR}";			\
		${ECHO} $$i; $$i;					\
	done
	@for f in qp-decode qp-encode base64-decode base64-encode; do	\
		i="${INSTALL_PROGRAM} ${WRKSRC}/$$f ${BINDIR}";		\
		${ECHO} $$i; $$i;					\
	done

.include "../../mk/bsd.pkg.mk"
