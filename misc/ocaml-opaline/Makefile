# $NetBSD: Makefile,v 1.7 2019/07/03 07:19:04 nia Exp $

GITHUB_PROJECT=	opaline
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.3.2
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jaapb/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/jaapb/opaline
COMMENT=	Lightweight OCaml/opam installer
LICENSE=	mit

INSTALLATION_DIRS+=	bin

.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
MAKE_ENV+=	OPTNESS=native
.else
MAKE_ENV+=	OPTNESS=byte
.endif

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../misc/ocaml-opam-file-format/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
