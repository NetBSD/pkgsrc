# $NetBSD: Makefile,v 1.5 2012/10/31 11:16:46 asau Exp $

DISTNAME=	cmph-1.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cmph/}

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	http://cmph.sourceforge.net/
COMMENT=	C Minimal Perfect Hashing Library
LICENSE=	gnu-lgpl-v2 OR mpl-1.1

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

TEST_DIRS=		tests
TEST_TARGET=	check

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
