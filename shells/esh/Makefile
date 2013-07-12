# $NetBSD: Makefile,v 1.30 2013/07/12 17:25:09 wiz Exp $

DISTNAME=		esh-0.8
PKGREVISION=		4
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Unix shell with Lisp-like syntax

WRKSRC=			${WRKDIR}/esh
PKG_SHELL=		bin/esh
INFO_FILES=		yes
INSTALLATION_DIRS=	bin ${PKGINFODIR} share/doc/esh share/examples/esh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/esh ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/examples/*.esh 			\
	    ${DESTDIR}${PREFIX}/share/examples/esh
	${INSTALL_DATA} ${WRKSRC}/emacs/esh-mode.el 			\
	    ${DESTDIR}${PREFIX}/share/examples/esh
	cd ${WRKSRC}/doc; for f in *.info *.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};		\
	done
	cd ${WRKSRC}/doc && ${INSTALL_DATA} esh.html esh_toc.html	\
	    ${DESTDIR}${PREFIX}/share/doc/esh/

.include "../../mk/bsd.pkg.mk"
