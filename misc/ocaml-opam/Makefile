# $NetBSD: Makefile,v 1.8 2016/06/19 23:23:02 jaapb Exp $

VERSION=	1.2.2
GITHUB_PROJECT=	opam
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://opam.ocaml.org/
COMMENT=	OCaml package manager
LICENSE=	gnu-lgpl-v3
MAKE_JOBS_SAFE=	no

HAS_CONFIGURE=	yes
USE_TOOLS+=	gawk gmake

CONFIGURE_ARGS+=	--prefix=${PREFIX} --mandir=${PREFIX}/${PKGMANDIR}

BUILD_TARGET=	all
INSTALL_TARGET=	install libinstall
INSTALL_ENV+=	LIBINSTALL_DIR=${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}

.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../devel/ocaml-extlib/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../devel/ocamlgraph/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../misc/dose3/buildlink3.mk" # with ocamlgraph option
.include "../../misc/ocaml-cudf/buildlink3.mk"
.include "../../textproc/ocaml-jsonm/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
