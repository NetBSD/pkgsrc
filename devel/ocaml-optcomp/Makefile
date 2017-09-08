# $NetBSD: Makefile,v 1.11 2017/09/08 09:51:21 jaapb Exp $

VERSION=	1.6
GITHUB_PROJECT=	optcomp
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=diml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/diml/optcomp/
COMMENT=	OCaml syntax extension for optional compilation
LICENSE=	modified-bsd

SUPERSEDES=	optcomp-[0-9]*

OCAML_USE_OASIS=	yes

.include "../../mk/ocaml.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
