# $NetBSD: Makefile,v 1.11 2016/06/17 10:48:57 jaapb Exp $
#

VERSION=	0.7.1
GITHUB_PROJECT=	deriving
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${GITHUB_PROJECT}-ocsigen-${VERSION}
COMMENT=	Extension to OCaml for deriving functions from type declarations
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://github.com/ocsigen/deriving
LICENSE=	mit

USE_TOOLS=	gmake
OCAML_USE_OASIS=	yes
OCAML_FINDLIB_DIRS=	deriving

post-patch:
	cd ${WRKSRC} && oasis setup

# Package actually needs ocaml-oasis to be installed
.include "../../devel/ocaml-oasis/buildlink3.mk"
.include "../../devel/ocaml-optcomp/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
