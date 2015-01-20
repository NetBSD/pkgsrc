# $NetBSD: Makefile,v 1.1 2015/01/20 15:19:54 jaapb Exp $

VERSION=	0.1
PKGNAME=	ocaml-reactiveData-${VERSION}
DISTNAME=	${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://github.com/hhugo/reactiveData/archive/
DIST_SUBDIR=	ocaml-reactiveData

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://github.com/hhugo/reactiveData
COMMENT=	Functional reactive programming library
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/reactiveData-0.1
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
.include "../../mk/bsd.pkg.mk"
