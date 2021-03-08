# $NetBSD: Makefile,v 1.10 2021/03/08 08:13:07 jaapb Exp $

VERSION=	0.0.2
GITHUB_PROJECT=	uchar
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/uchar/
COMMENT=	Compatibility library for the OCaml UChar module
LICENSE=	gnu-lgpl-v2.1

INSTALLATION_DIRS=	${OCAML_SITELIBDIR}/uchar

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
	${INSTALL_DATA} ${WRKSRC}/pkg/META.empty ${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/uchar/META

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
