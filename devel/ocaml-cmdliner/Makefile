# $NetBSD: Makefile,v 1.26 2026/02/17 13:38:57 wiz Exp $

DISTNAME=	cmdliner-1.1.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
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
