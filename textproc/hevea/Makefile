# $NetBSD: Makefile,v 1.12 2005/09/29 13:20:46 tonio Exp $

DISTNAME=	hevea-1.08
CATEGORIES=	textproc
MASTER_SITES=	http://para.inria.fr/~maranget/hevea/distri/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://para.inria.fr/~maranget/hevea/
COMMENT=	LaTeX to HTML translator

BUILD_DEPENDS+=	ocaml>=3.07:../../lang/ocaml

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
MAKE_ENV+=	TARGET=opt
.else
MAKE_ENV+=	TARGET=byte
.endif

.include "../../mk/bsd.pkg.mk"
