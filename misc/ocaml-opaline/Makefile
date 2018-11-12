# $NetBSD: Makefile,v 1.5 2018/11/12 16:10:25 jaapb Exp $

GITHUB_PROJECT=	opaline
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.3.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jaapb/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://github.com/jaapb/opaline
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
