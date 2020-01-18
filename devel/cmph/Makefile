# $NetBSD: Makefile,v 1.8 2020/01/18 23:30:25 rillig Exp $

DISTNAME=	cmph-2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cmph/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cmph.sourceforge.net/
COMMENT=	C Minimal Perfect Hashing Library
LICENSE=	gnu-lgpl-v2 OR mpl-1.1

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

TEST_DIRS=	tests
TEST_TARGET=	check

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
