# $NetBSD: Makefile,v 1.9 2018/02/27 19:36:06 cheusov Exp $

DISTNAME=		libmaa-1.4.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dict/}

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		http://www.dict.org/
COMMENT=		General purpose data structures and functions
LICENSE=		mit

USE_LANGUAGES=		c
TEST_TARGET=		test

MAKE_ENV+=		MKSTATICLIB=yes

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"
