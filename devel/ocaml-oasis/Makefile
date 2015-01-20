# $NetBSD: Makefile,v 1.3 2015/01/20 14:24:35 jaapb Exp $

DISTNAME=	oasis-0.4.4
PKGREVISION=	2
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
