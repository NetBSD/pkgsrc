# $NetBSD: Makefile,v 1.2 2015/01/20 14:24:36 jaapb Exp $

VERSION=	1.2.0
PKGNAME=	ocaml-opam-${VERSION}
DISTNAME=	${VERSION}
DIST_SUBDIR=	ocaml-opam
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	https://github.com/ocaml/opam/archive/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/opam/archive/
COMMENT=	OCaml package manager
LICENSE=	gnu-lgpl-v3
MAKE_JOBS_SAFE=	no

HAS_CONFIGURE=	yes
USE_TOOLS+=	gawk gmake

WRKSRC=	${WRKDIR}/opam-${VERSION}

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
