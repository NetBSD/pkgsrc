# $NetBSD: Makefile,v 1.17 2003/04/29 21:34:02 jtb Exp $

DISTNAME=	vm-7.14
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.uni-mainz.de/pub/gnu/vm/ \
		ftp://tug.org/vm/ \
		ftp://ftp.uu.net/networking/mail/vm/ \
		ftp://psg.com/pub/vm/ \
		ftp://sunsite.cnlab-switch.ch/mirror/vm/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.wonderworks.com/vm/
COMMENT=	VM (View Mail) is an advanced mail user agent for Emacs

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "xemacs"
INFODIR=	${PREFIX}/lib/xemacs/site-packages/info
PIXMAPDIR=	${PREFIX}/lib/xemacs/site-packages/etc/vm
BINDIR=		${PREFIX}/bin
PLIST_SRC=	${PKGDIR}/PLIST.xemacs
.elif ${EMACS_FLAVOR} == "emacs"
INFODIR=	${PREFIX}/info
PIXMAPDIR=	${PREFIX}/share/emacs/site-lisp/vm/pixmaps
BINDIR=		${PREFIX}/bin
INFO_FILES=	vm.info
PLIST_SRC=	${PKGDIR}/PLIST.emacs
.endif
MAKEFLAGS+=	EMACS=${EMACS_BIN}

MAKE_ENV+=	LISPDIR=${EMACS_LISPPREFIX}/vm
MAKE_ENV+=	INFODIR=${INFODIR}
MAKE_ENV+=	PIXMAPDIR=${PIXMAPDIR}
MAKE_ENV+=	BINDIR=${BINDIR}

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/vm
	cd ${WRKSRC} && ${INSTALL_DATA} *.el* ${EMACS_LISPPREFIX}/vm
	${INSTALL_DATA_DIR} ${INFODIR}
	${INSTALL_DATA} ${WRKSRC}/*.info* ${INFODIR}
	${INSTALL_DATA_DIR} ${PIXMAPDIR}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.x[pb]m ${PIXMAPDIR}
	cd ${WRKSRC} && ${INSTALL_PROGRAM} qp-decode qp-encode		\
		base64-decode base64-encode ${BINDIR}

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
