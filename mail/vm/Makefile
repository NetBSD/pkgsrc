# $NetBSD: Makefile,v 1.1.1.1 2000/12/01 04:18:20 jtb Exp $

DISTNAME=		vm-6.87
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.uni-mainz.de/pub/gnu/vm/ \
			ftp://tug.org/vm/ \
			ftp://ftp.uu.net/networking/mail/vm/ \
			ftp://psg.com/pub/vm/ \
			ftp://sunsite.cnlab-switch.ch/mirror/vm/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.wonderworks.com/vm/

DEPENDS+=	 	emacs-[0-9]*:../../editors/emacs

WRKSRC=			${WRKDIR}/${PKGNAME}
INFO_FILES=		vm.info

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp/vm
	${INSTALL_DATA} ${WRKSRC}/*.el ${WRKSRC}/*.elc \
	${PREFIX}/share/emacs/site-lisp/vm
	${INSTALL_DATA} ${WRKSRC}/*.info* ${PREFIX}/info
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp/vm/pixmaps
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.x[pb]m \
	${PREFIX}/share/emacs/site-lisp/vm/pixmaps
	@for p in qp-decode qp-encode base64-decode base64-encode ; do \
	${INSTALL_PROGRAM} ${WRKSRC}/$$p ${PREFIX}/bin ; done

.include "../../mk/bsd.pkg.mk"
