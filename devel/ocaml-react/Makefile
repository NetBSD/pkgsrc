# $NetBSD: Makefile,v 1.10 2016/02/06 12:55:08 jaapb Exp $

DISTNAME=	react-1.2.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://erratique.ch/software/react/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://erratique.ch/software/react
COMMENT=	OCaml module for functional reactive programming
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	--prefix "${PREFIX}" --destdir "${DESTDIR}"
INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/react

#SUBST_CLASSES+=   destdir
#SUBST_STAGE.destdir=  post-configure
#SUBST_MESSAGE.destdir=  Changing install location to DESTDIR
#SUBST_FILES.destdir=  setup.ml
#SUBST_SED.destdir=      -e 's,"install" :: findlib_name,"install" :: "-destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,'

.include "../../mk/ocaml.mk"

do-build:
.if ${OCAML_USE_OPT_COMPILER} == yes
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ocaml pkg/build.ml native=true native-dynlink=true
.else
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ocaml pkg/build.ml
.endif

do-install:
	for i in react.cma react.cmi react.mli react_top.cma; do \
		${INSTALL_DATA} ${WRKSRC}/_build/src/$$i \
			${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/react; \
	done
.if ${OCAML_USE_OPT_COMPILER} == yes
	for i in react.a react.cmx react.cmxa react.cmxs react_top.a react_top.cmxa \
	react_top.cmxs; do \
		${INSTALL_DATA} ${WRKSRC}/_build/src/$$i \
			${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/react; \
	done
.endif
	${INSTALL_DATA} ${WRKSRC}/_build/pkg/META \
		${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/react

.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
