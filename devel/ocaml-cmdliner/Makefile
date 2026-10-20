# $NetBSD: Makefile,v 1.28 2026/10/20 20:05:50 alnsn Exp $

DISTNAME=	cmdliner-1.3.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/cmdliner/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://erratique.ch/software/cmdliner/
COMMENT=	Module for the declarative definition of command line interfaces
LICENSE=	isc

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
MAKE_JOBS_SAFE=	no
MAKE_FLAGS+=	PREFIX=${PREFIX} LIBDIR=${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/cmdliner DOCDIR=${DESTDIR}${PREFIX}/share/doc/cmdliner

INSTALL_TARGET=	install install-doc

.include "../../lang/ocaml/ocaml.mk"

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
