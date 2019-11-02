# $NetBSD: Makefile,v 1.4 2019/11/02 15:38:03 rillig Exp $

GITHUB_PROJECT=	macaque
DISTNAME=	${GITHUB_PROJECT}-0.7.4
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/macaque/
COMMENT=	Language for SQL queries in OCaml
LICENSE=	gnu-lgpl-v2.1

HAS_CONFIGURE=		yes
USE_LANGUAGES=		c
OCAML_USE_FINDLIB=	yes
OCAML_USE_OASIS_DYNRUN=	yes

.include "../../databases/pgocaml/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
