# $NetBSD: Makefile,v 1.6 2016/02/06 13:45:24 jaapb Exp $

DISTNAME=	oasis-0.4.4
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1391/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://oasis.forge.ocamlcore.org/
COMMENT=	Build system for OCaml projects
LICENSE=	gnu-lgpl-v2.1

OCAML_USE_OASIS=	yes

.include "../../devel/ocaml-odn/buildlink3.mk"
.include "../../devel/ocamlify/buildlink3.mk"
.include "../../devel/ocamlmod/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
