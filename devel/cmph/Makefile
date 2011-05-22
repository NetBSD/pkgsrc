# $NetBSD: Makefile,v 1.2 2011/05/22 11:33:31 alnsn Exp $

DISTNAME=	cmph-1.1
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
