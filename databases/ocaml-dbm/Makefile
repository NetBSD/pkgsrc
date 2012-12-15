# $NetBSD: Makefile,v 1.1 2012/12/15 10:25:52 jaapb Exp $
#

PKGNAME=	ocaml-dbm-${PKGVERSION}
DISTNAME=	camldbm-${PKGVERSION}
PKGVERSION=	1.0
CATEGORIES=	databases
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/728/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://camldbm.forge.ocamlcore.org/
COMMENT=	OCaml binding to the NDBM and GDBM database library
LICENSE=	gnu-lgpl-v2

HAS_CONFIGURE=	yes
MAKE_ENV+=	DESTDIR="${DESTDIR}"

INSTALLATION_DIRS=	lib/ocaml/stublibs

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
