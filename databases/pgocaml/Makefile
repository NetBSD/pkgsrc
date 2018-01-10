# $NetBSD: Makefile,v 1.9 2018/01/10 16:53:08 jaapb Exp $

DISTNAME=	pgocaml-2.3
PKGREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1597/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://pgocaml.forge.ocamlcore.org/
COMMENT=	Native PostgreSQL binding for OCaml
LICENSE=	gnu-lgpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c
CONFIGURE_ARGS+=	--enable-p4

OCAML_USE_OASIS= yes

.include "../../mk/ocaml.mk"

.include "../../devel/ocaml-batteries/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../textproc/ocaml-csv/buildlink3.mk"
.include "../../time/ocaml-calendar/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
