# $NetBSD: Makefile,v 1.26 2005/12/05 20:50:36 rillig Exp $

DISTNAME=	vm-7.19
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.uni-mainz.de/pub/software/gnu/vm/ \
		ftp://tug.org/vm/ \
		ftp://psg.com/pub/vm/ \
		ftp://sunsite.cnlab-switch.ch/mirror/vm/ \
		ftp://ftp.uu.net/networking/mail/vm/ \
		http://www.interhack.net/projects/vm/ \
		ftp://ftp.ccs.neu.edu/net/mirrors/VM/ \
		http://www.rge.com/pub/mail/vm/ \
		http://ftp.lip6.fr/pub/unix/mail/vm/ \
		http://ftp.jussieu.fr/pub/unix/mail/vm/ \
		ftp://ftp.surfnet.nl/pub/mail/vm/ \
		http://ftp.algx.net/pub/packages/mail/vm/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.wonderworks.com/vm/
COMMENT=	VM (View Mail) is an advanced mail user agent for Emacs

.include "../../mk/emacs.mk"

USE_MAKEINFO=	YES

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
MAKEFLAGS+=	EMACS=${EMACS_BIN:Q}

MAKE_ENV+=	LISPDIR=${EMACS_LISPPREFIX}/vm
MAKE_ENV+=	INFODIR=${INFODIR:Q}
MAKE_ENV+=	PIXMAPDIR=${PIXMAPDIR:Q}
MAKE_ENV+=	BINDIR=${BINDIR:Q}

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/vm
	cd ${WRKSRC} && ${INSTALL_DATA} *.el* ${EMACS_LISPPREFIX}/vm
	${INSTALL_DATA_DIR} ${INFODIR}
	${INSTALL_DATA} ${WRKSRC}/*.info* ${INFODIR}
	${INSTALL_DATA_DIR} ${PIXMAPDIR}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.x[pb]m ${PIXMAPDIR}
	cd ${WRKSRC} && ${INSTALL_PROGRAM} qp-decode qp-encode		\
		base64-decode base64-encode ${BINDIR}

.include "../../mk/bsd.pkg.mk"
