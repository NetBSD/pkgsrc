# $NetBSD: Makefile,v 1.5 2001/12/19 21:52:49 agc Exp $
#

DISTNAME=	camlp4-3.01.6
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/cristal/camlp4/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://caml.inria.fr/camlp4/
COMMENT=	Camlp4 is a Pre-Processor-Pretty-Printer for Objective Caml

DEPENDS+=	ocaml-3.01:../ocaml

USE_GMAKE=	yes

ALL_TARGET=	world
PLIST_SRC=      ${WRKDIR}/PLIST

do-configure:
		${SED} -e 's|\$${PREFIX}|${PREFIX}|g' < ${FILESDIR}/config-answers | (cd ${WRKSRC} && ./configure)

pre-build:
		if ! ${TEST} -x ${LOCALBASE}/bin/ocamlc.opt; then \
			${ECHO} "No optimized ocaml binaries found"; \
			cd ${WRKSRC}/config; \
			${MV} Makefile Makefile.orig; \
			${SED} -e "s/\.opt//g" Makefile.orig > Makefile; \
		fi

pre-install:
		if ${TEST} -x ${LOCALBASE}/bin/ocamlopt; then \
			cd ${WRKSRC}; \
			${GMAKE} opt; \
			${CAT} ${PKGDIR}/PLIST.opt > ${PLIST_SRC}; \
			${CAT} ${PKGDIR}/PLIST >> ${PLIST_SRC}; \
		else \
			${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}; \
		fi

.include "../../mk/bsd.pkg.mk"
