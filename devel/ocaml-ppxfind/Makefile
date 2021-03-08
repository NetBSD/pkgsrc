# $NetBSD: Makefile,v 1.4 2021/03/08 08:12:59 jaapb Exp $

GITHUB_PROJECT=	ppxfind
DISTNAME=	${GITHUB_PROJECT}-1.4
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=diml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/diml/ppxfind/
COMMENT=	OCamlfind ppx tool
LICENSE=	modified-bsd

OCAML_USE_DUNE=		yes
INSTALL_UNSTRIPPED=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
