# $NetBSD: Makefile,v 1.2 2016/04/03 12:45:57 joerg Exp $
#

DISTNAME=	ocaml-zarith-1.4.1
CATEGORIES=	math
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1574/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://forge.ocamlcore.org/projects/zarith
COMMENT=	OCaml arithmetic library for arbitrary precision integers
LICENSE=	gnu-lgpl-v2

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

# zarith library creation is racy
MAKE_JOBS_SAFE=	no

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	DESTDIR=${DESTDIR}
USE_TOOLS+=	gmake perl

INSTALLATION_DIRS=	lib/ocaml/site-lib

WRKSRC=		${WRKDIR}/${DISTNAME:S/ocaml-//}

REPLACE_PERL+=	z_pp.pl

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
