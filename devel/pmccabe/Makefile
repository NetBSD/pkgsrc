# $NetBSD: Makefile,v 1.8 2008/10/18 11:00:09 obache Exp $

DISTNAME=	pmccabe_2.2-3
PKGNAME=	pmccabe-2.2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/p/pmccabe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.parisc-linux.org/~bame/pmccabe/
COMMENT=	Measures the McCabe cyclomatic complexity of C and C++

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pmccabe

CFLAGS+=	-D__unix=1

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
