# $NetBSD: Makefile,v 1.3 2012/04/17 17:41:40 joerg Exp $

DISTNAME=	cmph-1.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cmph/}

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	http://cmph.sourceforge.net/
COMMENT=	C Minimal Perfect Hashing Library
LICENSE=	gnu-lgpl-v2 OR mpl-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

TEST_DIRS=		tests
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
