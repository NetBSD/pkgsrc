# $NetBSD: Makefile,v 1.2 2001/01/28 03:16:54 jtb Exp $

DISTNAME=		vm-6.90
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.uni-mainz.de/pub/gnu/vm/ \
			ftp://tug.org/vm/ \
			ftp://ftp.uu.net/networking/mail/vm/ \
			ftp://psg.com/pub/vm/ \
			ftp://sunsite.cnlab-switch.ch/mirror/vm/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.wonderworks.com/vm/

.include "../../mk/bsd.prefs.mk"

.if defined(USE_XEMACS)
DEPENDS+=	 	xemacs>=19.14:../../editors/xemacs
MAKE_ENV+=		EMACS=xemacs
MAKE_ENV+=		LISPDIR="${PREFIX}/lib/xemacs/xemacs-packages/lisp/vm"
MAKE_ENV+=		INFODIR="${PREFIX}/lib/xemacs/xemacs-packages/info"
MAKE_ENV+=		PIXMAPDIR="${PREFIX}/lib/xemacs/xemacs-packages/etc/vm"
MAKE_ENV+=		BINDIR="${PREFIX}/bin"
PLIST_SRC=		${PKGDIR}/PLIST.xemacs
.else
DEPENDS+=	 	emacs>=19.34:../../editors/emacs
MAKE_ENV+=		EMACS=emacs
MAKE_ENV+=		LISPDIR="${PREFIX}/share/emacs/site-lisp/vm"
MAKE_ENV+=		INFODIR="${PREFIX}/info"
MAKE_ENV+=		PIXMAPDIR="${PREFIX}/share/emacs/site-lisp/vm/pixmaps"
MAKE_ENV+=		BINDIR="${PREFIX}/bin"
INFO_FILES=		vm.info
PLIST_SRC=		${PKGDIR}/PLIST.emacs
.endif

do-install:
	${INSTALL_DATA_DIR} ${LISPDIR}
	@for a in ${WRKSRC}/*.el ${WRKSRC}/*.elc; do	\
		a="${INSTALL_DATA} $$a ${LISPDIR}";	\
		${ECHO} $$a; $$a;			\
	done
	@for b in ${WRKSRC}/*.info*; do			\
		b="${INSTALL_DATA} $$b ${INFODIR}";	\
		${ECHO} $$b; $$b;			\
	done
	${INSTALL_DATA_DIR} ${PIXMAPDIR}
	@for c in ${WRKSRC}/pixmaps/*.x[pb]m; do	\
		c="${INSTALL_DATA} $$c ${PIXMAPDIR}";	\
		${ECHO} $$c; $$c;			\
	done
	@for p in qp-decode qp-encode base64-decode base64-encode ; do	\
		d="${INSTALL_PROGRAM} ${WRKSRC}/$$p ${BINDIR}";		\
		${ECHO} $$d; $$d;					\
	done

.include "../../mk/bsd.pkg.mk"
