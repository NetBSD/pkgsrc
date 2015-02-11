# $NetBSD: Makefile,v 1.3 2015/02/11 13:59:17 jaapb Exp $

DISTNAME=	dose3-3.3-beta2
PKGNAME= dose3-3.3beta2
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/file/34180/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://gforge.inria.fr/projects/dose/
COMMENT=	Package repository analysis toolkit
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	aclocal automake autoconf gmake pod2man
MAKE_JOBS_SAFE=	no
OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"
.include "options.mk"

.if ${OCAML_USE_OPT_COMPILER} != "yes"
CONFIGURE_ARGS+=	--with-bytecodeonly
.endif

pre-configure:
	cd ${WRKSRC} && aclocal -I m4 && autoconf

.include "../../devel/ocaml-extlib/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../misc/ocaml-cudf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
