# $NetBSD: Makefile,v 1.7 2016/02/06 12:45:35 jaapb Exp $

DISTNAME=	uutf-0.9.4
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://erratique.ch/software/uutf/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://erratique.ch/software/uutf/releases/
COMMENT=	Unicode library for OCaml
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/uutf
OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"

do-build:
.if ${OCAML_USE_OPT_COMPILER} == "yes"
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ocaml ./pkg/build.ml \
		native=true native-dynlink=true cmdliner=false
.else
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ocaml ./pkg/build.ml \
		native=false native-dynlink=false cmdliner=false
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/_build/pkg/META ${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/uutf
	for i in uutf.mli uutf.cmi uutf.cma; do \
		${INSTALL_DATA} ${WRKSRC}/_build/src/$$i ${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/uutf; \
	done
.if ${OCAML_USE_OPT_COMPILER} == "yes"
	for i in uutf.cmx uutf.a uutf.cmxa uutf.cmxs; do \
		${INSTALL_DATA} ${WRKSRC}/_build/src/$$i ${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/uutf; \
	done
.endif

.include "../../mk/bsd.pkg.mk"
