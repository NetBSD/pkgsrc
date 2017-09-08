# $NetBSD: Makefile,v 1.15 2017/09/08 09:51:20 jaapb Exp $
#

VERSION=	0.7.1
GITHUB_PROJECT=	deriving
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${GITHUB_PROJECT}-ocsigen-${VERSION}
PKGREVISION=	3
COMMENT=	Extension to OCaml for deriving functions from type declarations
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/deriving
LICENSE=	mit

USE_TOOLS=	gmake
OCAML_USE_OASIS_DYNRUN=	yes
OCAML_FINDLIB_DIRS=	deriving

# Package actually needs ocaml-oasis to be installed
.include "../../devel/ocaml-optcomp/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
