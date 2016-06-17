# $NetBSD: Makefile,v 1.9 2016/06/17 15:33:24 jaapb Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	cmdliner-0.9.8
CATEGORIES=	devel
MASTER_SITES=	http://erratique.ch/software/cmdliner/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://erratique.ch/software/cmdliner/
COMMENT=	Module for the declarative definition of command line interfaces
LICENSE=	modified-bsd

USE_LANGUAGES=	c
OCAML_USE_FINDLIB=	yes
INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/cmdliner

.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
NATIVE=	true
.else
NATIVE=	false
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ocaml ./pkg/build.ml \
		native=${NATIVE} native-dynlink=${NATIVE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/_build/pkg/META ${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/cmdliner
	for i in cmdliner.mli cmdliner.cmi cmdliner.cma; do \
		${INSTALL_DATA} ${WRKSRC}/_build/src/$$i ${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/cmdliner; \
	done
.if ${OCAML_USE_OPT_COMPILER} == "yes"
	for i in cmdliner.cmx cmdliner.a cmdliner.cmxa cmdliner.cmxs; do \
		${INSTALL_DATA} ${WRKSRC}/_build/src/$$i ${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/cmdliner; \
	done
.endif

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
