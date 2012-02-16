# $NetBSD: Makefile,v 1.10 2012/02/16 18:48:05 hans Exp $

DISTNAME=	pmccabe-2.5-CVS20081026
PKGNAME=	pmccabe-2.5
CATEGORIES=	devel
MASTER_SITES=	http://cvs.parisc-linux.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.parisc-linux.org/~bame/pmccabe/
COMMENT=	Measures the McCabe cyclomatic complexity of C and C++

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pmccabe

CFLAGS+=	-D__unix=1
MAKE_ENV+=	INSTALL=${TOOLS_PATH.install:Q}

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
