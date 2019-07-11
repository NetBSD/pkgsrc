# $NetBSD: Makefile,v 1.4 2019/07/11 11:20:06 sevan Exp $

DISTNAME=	picopb-20150628
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tgz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	ftp://ftp.netbsd.org/pub/pkgsrc/distfiles/LOCAL_PORTS/
COMMENT=	Small implementation of Google protocol buffers in C
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	yacc
USE_FEATURES+=	strnlen

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
