# $NetBSD: Makefile,v 1.10 2001/12/11 15:49:25 wiz Exp $

DISTNAME=	vm-7.00
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
MAKE_ENV+=	LISPDIR=${PREFIX}/lib/xemacs/xemacs-packages/lisp/vm
MAKE_ENV+=	INFODIR=${PREFIX}/lib/xemacs/xemacs-packages/info
MAKE_ENV+=	PIXMAPDIR=${PREFIX}/lib/xemacs/xemacs-packages/etc/vm
MAKE_ENV+=	BINDIR=${PREFIX}/bin
PLIST_SRC=	${PKGDIR}/PLIST.xemacs
.else
DEPENDS+=	emacs>=19.34:../../editors/emacs
MAKE_ENV+=	EMACS=emacs
MAKE_ENV+=	LISPDIR=${PREFIX}/share/emacs/site-lisp/vm
MAKE_ENV+=	INFODIR=${PREFIX}/info
MAKE_ENV+=	PIXMAPDIR=${PREFIX}/share/emacs/site-lisp/vm/pixmaps
MAKE_ENV+=	BINDIR=${PREFIX}/bin
INFO_FILES=	vm.info
PLIST_SRC=	${PKGDIR}/PLIST.emacs
.endif

do-install:
	${INSTALL_DATA_DIR} ${LISPDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.el* ${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.info* ${INFODIR}
	${INSTALL_DATA_DIR} ${PIXMAPDIR}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.x[pb]m ${PIXMAPDIR}
	cd ${WRKSRC} && ${INSTALL_PROGRAM} qp-decode qp-encode		\
		base64-decode base64-encode ${BINDIR}

.include "../../mk/bsd.pkg.mk"
