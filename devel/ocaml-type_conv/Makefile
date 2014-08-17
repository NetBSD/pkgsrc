# $NetBSD: Makefile,v 1.1 2014/08/17 13:22:17 jaapb Exp $


DISTNAME=	type_conv-${VERS}
VERS=			111.13.00
CATEGORIES=	devel
MASTER_SITES=	https://github.com/janestreet/type_conv/archive/
DISTFILES=	${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=	ocaml-type_conv

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/type_conv/
COMMENT=	Support library for OCaml preprocessor type conversions
LICENSE=	apache-2.0 AND modified-bsd

WRKSRC=	${WRKDIR}/type_conv-${VERS}
USE_TOOLS+=	gmake

OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
