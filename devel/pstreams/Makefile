# $NetBSD: Makefile,v 1.2 2012/10/03 21:55:54 wiz Exp $
#

DISTNAME=	pstreams-0.7.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pstreams/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pstreams.sourceforge.net/
COMMENT=	POSIX Process Control in C++
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++

USE_TOOLS+=	perl:build

INSTALL_MAKE_FLAGS=	prefix=${PREFIX}

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
