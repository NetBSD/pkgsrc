# $NetBSD: Makefile,v 1.10 2017/07/30 22:32:15 wiz Exp $

GITHUB_PROJECT=	reactiveData
DISTNAME=	${GITHUB_PROJECT}-0.2.1
PKGREVISION=	1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/reactiveData
COMMENT=	Functional reactive programming library
LICENSE=	gnu-lgpl-v2.1

OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"

INSTALL_FILES=	cma cmi mli
.if ${OCAML_USE_OPT_COMPILER} == "yes"
MAKE_ENV+=	NATIVE=true
INSTALL_FILES+=	a cmx cmxa cmxs
.else
MAKE_ENV+=	NATIVE=false
.endif
BUILD_TARGET=	build

INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/reactiveData

do-install:
	${INSTALL_DATA} ${WRKSRC}/_build/pkg/META \
	${DESTDIR}/${PREFIX}/${OCAML_SITELIBDIR}/reactiveData
	for i in ${INSTALL_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/_build/src/reactiveData.$$i \
		${DESTDIR}/${PREFIX}/${OCAML_SITELIBDIR}/reactiveData; \
	done

.include "../../devel/ocaml-react/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
