# $NetBSD: Makefile,v 1.34 2026/03/01 12:38:38 gdt Exp $

DISTNAME=	hevea-2.35
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://hevea.inria.fr/distri/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://hevea.inria.fr/
COMMENT=	LaTeX to HTML translator
LICENSE=	qpl-v1.0

MAKE_ENV+=	DESTDIR=${DESTDIR}

.include "../../lang/ocaml/ocaml.mk"
.if !empty(OCAML_USE_OPT_COMPILER:M[Yy][Ee][Ss])
MAKE_ENV+=	TARGET=opt
.else
MAKE_ENV+=	TARGET=byte
.endif

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
