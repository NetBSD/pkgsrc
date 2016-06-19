# $NetBSD: Makefile,v 1.7 2016/06/19 10:36:58 jaapb Exp $

DISTNAME=	dose3-5.0~rc2
PKGNAME=	dose3-5.0rc2
CATEGORIES=	misc
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/file/35957/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://gforge.inria.fr/projects/dose/
COMMENT=	Package repository analysis toolkit
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	aclocal automake autoconf gmake pod2man
MAKE_JOBS_SAFE=	no
OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} != "yes"
CONFIGURE_ARGS+=	--with-bytecodeonly
.endif

pre-configure:
	cd ${WRKSRC} && aclocal -I m4 && autoconf

.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../devel/ocaml-extlib/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocamlgraph/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../misc/ocaml-cudf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
