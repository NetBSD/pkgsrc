# $NetBSD: Makefile,v 1.26 2010/02/12 00:23:07 joerg Exp $

DISTNAME=		esh-0.8
PKGREVISION=		2
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Unix shell with Lisp-like syntax

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/esh
PKG_SHELL=		bin/esh
INFO_FILES=		# PLIST
INSTALLATION_DIRS=	bin ${PKGINFODIR} share/doc/esh share/examples/esh \
			share/emacs/site-lisp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/esh ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/examples/*.esh 			\
	    ${DESTDIR}${PREFIX}/share/examples/esh
	${INSTALL_DATA} ${WRKSRC}/emacs/esh-mode.el 			\
	    ${DESTDIR}${PREFIX}/share/emacs/site-lisp
	cd ${WRKSRC}/doc; for f in *.info *.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};		\
	done
	cd ${WRKSRC}/doc && ${INSTALL_DATA} esh.html esh_toc.html	\
	    ${DESTDIR}${PREFIX}/share/doc/esh/

.include "../../mk/bsd.pkg.mk"
