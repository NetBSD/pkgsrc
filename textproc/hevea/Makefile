# $NetBSD: Makefile,v 1.13 2006/01/13 09:26:38 tonio Exp $

DISTNAME=	hevea-1.08
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://para.inria.fr/~maranget/hevea/distri/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://para.inria.fr/~maranget/hevea/
COMMENT=	LaTeX to HTML translator

BUILD_DEPENDS+=	ocaml>=3.07:../../lang/ocaml

DIST_SUBDIR=    ${PKGNAME_NOREV}
.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
MAKE_ENV+=	TARGET=opt
.else
MAKE_ENV+=	TARGET=byte
.endif

.include "../../mk/bsd.pkg.mk"
