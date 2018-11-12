# $NetBSD: Makefile,v 1.8 2018/11/12 16:10:27 jaapb Exp $

GITHUB_PROJECT=	markup.ml
GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	markup-0.7.6
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=aantron/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/aantron/markup.ml/
COMMENT=	Error-recovering streaming HTML5 and XML parsers for OCaml
LICENSE=	2-clause-bsd

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

OCAML_USE_JBUILDER=	yes

do-configure:
	${RUN} cd ${WRKSRC} && ocaml src/configure.ml

.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../textproc/ocaml-uutf/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
