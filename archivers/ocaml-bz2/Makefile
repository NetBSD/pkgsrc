# $NetBSD: Makefile,v 1.24 2026/01/14 10:47:37 wiz Exp $

PKGNAME=	ocaml-bz2-${VERSION}
DISTNAME=	camlbz2-${VERSION}
VERSION=	0.7.0
CATEGORIES=	archivers
MASTER_SITES=	https://gitlab.com/irill/camlbz2/-/archive/${VERSION}/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	OCaml library to manipulate bz2 archives
HOMEPAGE=	https://gitlab.com/irill/camlbz2
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake autoconf
MAKE_JOBS_SAFE=		no
OCAML_USE_FINDLIB=	yes

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.prefs.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
