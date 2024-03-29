# $NetBSD: Makefile,v 1.115 2023/11/14 14:01:35 wiz Exp $

DISTNAME=	frama-c-25.0-Manganese
PKGNAME=	${DISTNAME:S/-Manganese//}
PKGREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	https://frama-c.com/download/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	https://frama-c.com/
COMMENT=	Extensible platform dedicated to source-code analysis of C software
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	autoconf bash gmake
GNU_CONFIGURE=	yes

REPLACE_SH+=		bin/frama-c-script
REPLACE_SH+=		src/plugins/e-acsl/scripts/e-acsl-gcc.sh
REPLACE_SH+=		share/analysis-scripts/*.sh
REPLACE_PERL+=		share/analysis-scripts/*.pl
REPLACE_PYTHON+=	share/analysis-scripts/*.py

OCAML_USE_FINDLIB=	yes

.include "options.mk"

# WARNING: you must build ocamlgraph with ocaml-lablgtk support
# (not the default) or the build fails with missing module "Dgraph".

.include "../../devel/ocamlgraph/buildlink3.mk"
.include "../../devel/ocaml-yojson/buildlink3.mk"
.include "../../devel/ocaml-ppx_import/buildlink3.mk"
.include "../../devel/ocaml-ppx_deriving/buildlink3.mk"
.include "../../math/ocaml-num/buildlink3.mk"
.include "../../math/ocaml-zarith/buildlink3.mk"

.include "../../lang/ocaml/ocaml.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
