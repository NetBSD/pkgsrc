# $NetBSD: Makefile,v 1.4 2003/06/25 21:01:47 jmc Exp $

DISTNAME=	hevea-1.05
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/para/hevea/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://para.inria.fr/~maranget/hevea/
COMMENT=	LaTeX to HTML translator

DEPENDS+=	ocaml>=3.00:../../lang/ocaml

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
MAKE_ENV+=	TARGET=opt
.else
MAKE_ENV+=	TARGET=byte
.endif

.include "../../mk/bsd.pkg.mk"
