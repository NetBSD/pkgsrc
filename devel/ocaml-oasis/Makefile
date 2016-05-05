# $NetBSD: Makefile,v 1.7 2016/05/05 16:06:51 jaapb Exp $

DISTNAME=	oasis-0.4.6
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1604/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://oasis.forge.ocamlcore.org/
COMMENT=	Build system for OCaml projects
LICENSE=	gnu-lgpl-v2.1

OCAML_USE_OASIS=	yes
OCAML_FINDLIB_DIRS=	${OCAML_SITELIBDIR}/oasis

.include "../../devel/ocaml-odn/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocamlify/buildlink3.mk"
.include "../../devel/ocamlmod/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
