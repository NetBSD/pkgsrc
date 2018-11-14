# $NetBSD: Makefile,v 1.85 2018/11/14 22:21:14 kleink Exp $
#

DISTNAME=	frama-c-Phosphorus-20170501
PKGNAME=	${DISTNAME:S/-Phosphorus//}
PKGREVISION=	17
CATEGORIES=	devel
MASTER_SITES=	https://frama-c.com/download/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	https://frama-c.com/
COMMENT=	Extensible platform dedicated to source-code analysis of C software
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	gmake autoconf
GNU_CONFIGURE=	yes

OCAML_USE_FINDLIB=	yes

.include "options.mk"

# WARNING: you must build ocamlgraph with ocaml-lablgtk support
# (not the default) or the build fails with missing module "Dgraph".

.include "../../devel/ocamlgraph/buildlink3.mk"
.include "../../math/ocaml-zarith/buildlink3.mk"

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
