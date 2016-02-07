# $NetBSD: Makefile,v 1.1 2016/02/07 21:43:03 markd Exp $
#

DISTNAME=	ocaml-zarith-1.4.1
CATEGORIES=	math
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1574/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://forge.ocamlcore.org/projects/zarith
COMMENT=	OCaml arithmetic library for arbitrary precision integers
LICENSE=	gnu-lgpl-v2

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	DESTDIR=${DESTDIR}
USE_TOOLS+=	gmake perl

INSTALLATION_DIRS=	lib/ocaml/site-lib

WRKSRC=		${WRKDIR}/${DISTNAME:S/ocaml-//}

REPLACE_PERL+=	z_pp.pl

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
