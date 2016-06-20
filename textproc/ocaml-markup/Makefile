# $NetBSD: Makefile,v 1.1 2016/06/20 11:08:31 jaapb Exp $

VERSION=	0.7.2
GITHUB_PROJECT=	markup.ml
DISTNAME=	markup-${VERSION}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=aantron/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/aantron/markup.ml/
COMMENT=	Error-recovering streaming HTML5 and XML parsers for OCaml
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${VERSION}
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake
OCAML_USE_FINDLIB=	yes

BUILD_TARGET=	build
INSTALL_TARGET=	ocamlfind-install

.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../textproc/ocaml-uutf/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
