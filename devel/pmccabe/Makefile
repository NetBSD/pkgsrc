# $NetBSD: Makefile,v 1.13 2017/09/03 08:36:53 wiz Exp $

DISTNAME=	pmccabe-2.5-CVS20081026
PKGNAME=	pmccabe-2.5
CATEGORIES=	devel
MASTER_SITES=	http://cvs.parisc-linux.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.parisc-linux.org/~bame/pmccabe/
COMMENT=	Measures the McCabe cyclomatic complexity of C and C++

WRKSRC=		${WRKDIR}/pmccabe

CFLAGS+=	-D__unix=1
MAKE_ENV+=	INSTALL=${TOOLS_PATH.install:Q}

TEST_TARGET=	test

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
