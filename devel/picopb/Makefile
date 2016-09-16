# $NetBSD: Makefile,v 1.3 2016/09/16 20:54:32 wiedi Exp $

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

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
