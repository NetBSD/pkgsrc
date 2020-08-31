# $NetBSD: Makefile,v 1.14 2020/08/31 18:09:19 wiz Exp $
#

DISTNAME=	pstreams-0.8.1
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pstreams/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pstreams.sourceforge.net/
COMMENT=	POSIX Process Control in C++
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c++

USE_TOOLS+=	perl:build

INSTALL_MAKE_FLAGS=	prefix=${PREFIX}

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
