# $NetBSD: Makefile,v 1.19 2018/11/27 15:56:11 jaapb Exp $

DISTNAME=	cmdliner-1.0.3
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://erratique.ch/software/cmdliner/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://erratique.ch/software/cmdliner/
COMMENT=	Module for the declarative definition of command line interfaces
LICENSE=	isc

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
MAKE_JOBS_SAFE=	no
MAKE_ENV+=	PREFIX=${PREFIX} LIBDIR=${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/cmdliner DOCDIR=${DESTDIR}${PREFIX}/share/doc/cmdliner

INSTALL_TARGET=	install install-doc

.include "../../mk/ocaml.mk"

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
