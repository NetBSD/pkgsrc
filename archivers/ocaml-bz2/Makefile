# $NetBSD: Makefile,v 1.26 2026/03/01 12:38:18 gdt Exp $

PKGNAME=	ocaml-bz2-${VERSION}
PKGREVISION=	2
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
