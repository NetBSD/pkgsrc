# $NetBSD: Makefile,v 1.26 2026/10/25 00:49:33 alnsn Exp $

DISTNAME=	dose3-7.0.0
CATEGORIES=	misc
MASTER_SITES=	https://gitlab.com/irill/dose3/-/archive/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mancoosi.org/software/
COMMENT=	Package repository analysis toolkit
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=		# none
OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	dose3 dose3-extra
OPAM_INSTALL_FILES=	${DUNE_BUILD_PACKAGES}

.include "../../lang/ocaml/ocaml.mk"
.include "../../archivers/ocaml-bz2/buildlink3.mk"
.include "../../archivers/ocaml-zip/buildlink3.mk"
.include "../../devel/ocaml-base64/buildlink3.mk"
.include "../../devel/ocaml-extlib/buildlink3.mk"
.include "../../devel/ocaml-parmap/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../devel/ocaml-stdlib-shims/buildlink3.mk"
.include "../../devel/ocamlgraph/buildlink3.mk"
.include "../../misc/ocaml-cudf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
