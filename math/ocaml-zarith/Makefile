# $NetBSD: Makefile,v 1.4 2016/06/25 14:31:13 jaapb Exp $
#

DISTNAME=	ocaml-zarith-1.4.1
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1574/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://forge.ocamlcore.org/projects/zarith
COMMENT=	OCaml arithmetic library for arbitrary precision integers
LICENSE=	gnu-lgpl-v2

# zarith library creation is racy
MAKE_JOBS_SAFE=	no

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	DESTDIR=${DESTDIR}
USE_TOOLS+=	gmake perl

OCAML_USE_FINDLIB=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/ocaml-//}

REPLACE_PERL+=	z_pp.pl

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
