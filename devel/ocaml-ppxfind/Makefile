# $NetBSD: Makefile,v 1.5 2022/05/24 18:51:51 jaapb Exp $

GITHUB_PROJECT=	ppxfind
DISTNAME=	${GITHUB_PROJECT}-1.4
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=diml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/diml/ppxfind/
COMMENT=	OCamlfind ppx tool
LICENSE=	modified-bsd

OCAML_USE_DUNE=		yes
INSTALL_UNSTRIPPED=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
