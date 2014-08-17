# $NetBSD: Makefile,v 1.5 2014/08/17 13:54:54 jaapb Exp $
#

DISTNAME=	0.6.2
PKGNAME=	ocaml-deriving-ocsigen-${DISTNAME}
COMMENT=	Extension to OCaml for deriving functions from type declarations
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ocsigen/deriving/archive/
DIST_SUBDIR=	ocaml-deriving-ocsigen

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://github.com/ocsigen/deriving
LICENSE=	mit

WRKSRC=	${WRKDIR}/deriving-0.6.2
USE_TOOLS=	gmake
OCAML_USE_OASIS=	yes

INSTALLATION_DIRS= lib/ocaml/site-lib

# Package actually needs ocaml-oasis to be installed
.include "../../devel/ocaml-oasis/buildlink3.mk"
.include "../../devel/ocaml-optcomp/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
