# $NetBSD: Makefile,v 1.7 2016/04/12 16:05:21 jaapb Exp $


DISTNAME=	type_conv-${VERS}
PKGNAME=	ocaml-${DISTNAME}
VERS=			113.00.02
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/type_conv/archive/}
DISTFILES=	${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=	ocaml-type_conv

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/type_conv/
COMMENT=	Support library for OCaml preprocessor type conversions
LICENSE=	apache-2.0 AND modified-bsd

WRKSRC=	${WRKDIR}/type_conv-${VERS}
USE_TOOLS+=	gmake

OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_DIRS=	${OCAML_SITELIBDIR}/type_conv

.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
