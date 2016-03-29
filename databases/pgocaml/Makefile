# $NetBSD: Makefile,v 1.2 2016/03/29 22:04:26 joerg Exp $

DISTNAME=	pgocaml-2.2
CATEGORIES=	databases
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1506/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://pgocaml.forge.ocamlcore.org/
COMMENT=	Native PostgreSQL binding for OCaml
LICENSE=	gnu-lgpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c

OCAML_USE_OASIS= yes

.include "../../mk/ocaml.mk"

.include "../../devel/ocaml-batteries/buildlink3.mk"
.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../textproc/ocaml-csv/buildlink3.mk"
.include "../../time/ocaml-calendar/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
