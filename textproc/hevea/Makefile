# $NetBSD: Makefile,v 1.3 2003/06/23 20:36:14 jtb Exp $

DISTNAME=	hevea-1.05
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/para/hevea/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://para.inria.fr/~maranget/hevea/
COMMENT=	LaTeX to HTML translator

DEPENDS+=	ocaml>=3.00:../../lang/ocaml

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
ALL_TARGET=opt
.else
ALL_TARGET=byte
.endif

.include "../../mk/bsd.pkg.mk"
