# $NetBSD: Makefile,v 1.18 2018/11/12 16:10:17 jaapb Exp $

PKGNAME=	ocaml-bz2-${VERSION}
DISTNAME=	camlbz2-${VERSION}
VERSION=	0.6.0
PKGREVISION=	15
CATEGORIES=	archivers
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/72/

MAINTAINER=	jaapb@NetBSD.org
COMMENT=	OCaml library to manipulate bz2 archives
HOMEPAGE=	http://camlbz2.forge.ocamlcore.org/
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_JOBS_SAFE=	no
OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.prefs.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
