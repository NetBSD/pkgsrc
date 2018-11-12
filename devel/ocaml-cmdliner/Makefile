# $NetBSD: Makefile,v 1.18 2018/11/12 16:10:16 jaapb Exp $

PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	4
DISTNAME=	cmdliner-1.0.2
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
