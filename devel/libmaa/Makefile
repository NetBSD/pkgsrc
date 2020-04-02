# $NetBSD: Makefile,v 1.16 2020/04/02 16:50:23 cheusov Exp $

DISTNAME=		libmaa-1.4.6
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dict/}

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		http://www.dict.org/
COMMENT=		General purpose data structures and functions
LICENSE=		mit

USE_LANGUAGES=		c
TEST_TARGET=		test

MAKE_ENV+=		MKSTATICLIB=yes NOSUBDIR=err

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"
