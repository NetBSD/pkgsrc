# $NetBSD: Makefile,v 1.6 2014/10/09 20:25:24 jaapb Exp $
#

VERSION=	0.7
DISTNAME=	${VERSION}
PKGNAME=	ocaml-deriving-ocsigen-${VERSION}
COMMENT=	Extension to OCaml for deriving functions from type declarations
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ocsigen/deriving/archive/
DIST_SUBDIR=	ocaml-deriving-ocsigen

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://github.com/ocsigen/deriving
LICENSE=	mit

WRKSRC=	${WRKDIR}/deriving-${VERSION}
USE_TOOLS=	gmake
OCAML_USE_OASIS=	yes

post-patch:
	cd ${WRKSRC} && oasis setup

# Package actually needs ocaml-oasis to be installed
.include "../../devel/ocaml-oasis/buildlink3.mk"
.include "../../devel/ocaml-optcomp/buildlink3.mk"
BUILDLINK_API_DEPENDS.ocaml-optcomp+=   ocaml-optcomp>=1.6
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
