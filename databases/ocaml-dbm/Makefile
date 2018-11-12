# $NetBSD: Makefile,v 1.19 2018/11/12 16:10:16 jaapb Exp $
#

PKGNAME=	ocaml-dbm-${VERSION}
DISTNAME=	camldbm-${VERSION}
VERSION=	1.0
PKGREVISION=	17
CATEGORIES=	databases
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/728/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://camldbm.forge.ocamlcore.org/
COMMENT=	OCaml binding to the NDBM and GDBM database library
LICENSE=	gnu-lgpl-v2

CONFLICTS=	ocaml-findlib<1.4nb1

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_ENV+=	HAS_OCAMLOPT="${OCAML_USE_OPT_COMPILER}"
OCAML_USE_FINDLIB=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/META ${DESTDIR}${PREFIX}/lib/ocaml/site-lib/dbm

.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
