# $NetBSD: Makefile,v 1.19 2024/05/29 15:21:42 cheusov Exp $

DISTNAME=		libmaa-1.5.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dict/}

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		http://www.dict.org/
COMMENT=		General purpose data structures and functions
LICENSE=		mit

USE_LANGUAGES=		c
TEST_TARGET=		test

TOOL_DEPENDS+=		mk-configure>=0.34.0:../../devel/mk-configure

MAKE_ENV+=		MKSTATICLIB=yes
INSTALL_TARGET=	install install-doc

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"
