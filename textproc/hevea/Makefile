# $NetBSD: Makefile,v 1.11 2005/05/16 05:09:21 jlam Exp $

DISTNAME=	hevea-1.07
CATEGORIES=	textproc
MASTER_SITES=	http://para.inria.fr/~maranget/hevea/distri/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://para.inria.fr/~maranget/hevea/
COMMENT=	LaTeX to HTML translator

BUILD_DEPENDS+=	ocaml>=3.07:../../lang/ocaml

USE_TOOLS+=	m4
MAKE_ENV+=	M4=${TOOLS_M4:Q}

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
MAKE_ENV+=	TARGET=opt
.else
MAKE_ENV+=	TARGET=byte
.endif

.include "../../mk/bsd.pkg.mk"
