# $NetBSD: Makefile,v 1.16 2022/02/15 10:28:38 nros Exp $
#

DISTNAME=	pstreams-1.0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pstreams/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pstreams.sourceforge.net/
COMMENT=	POSIX Process Control in C++
LICENSE=	boost-license

USE_LANGUAGES=	c++

USE_TOOLS+=	gmake

TEST_TARGET=	test

INSTALL_MAKE_FLAGS=	prefix=${PREFIX}
INSTALLATION_DIRS=	share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE_1_0.txt \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
