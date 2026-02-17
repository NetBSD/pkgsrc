# $NetBSD: Makefile,v 1.13 2026/02/17 13:39:10 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-0.3.3
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jaapb/}
GITHUB_PROJECT=	opaline
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaapb/opaline
COMMENT=	Lightweight OCaml/opam installer
LICENSE=	mit

INSTALLATION_DIRS+=	bin

.include "../../lang/ocaml/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
MAKE_ENV+=	OPTNESS=native
.else
MAKE_ENV+=	OPTNESS=byte
.endif

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../misc/ocaml-opam-file-format/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
