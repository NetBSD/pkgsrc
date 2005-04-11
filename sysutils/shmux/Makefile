# $NetBSD: Makefile,v 1.7 2005/04/11 21:47:29 tv Exp $

DISTNAME=	shmux-1.0b5
CATEGORIES=	sysutils
MASTER_SITES=	http://web.taranis.org/shmux/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://web.taranis.org/shmux/
COMMENT=	Shell Multiplexor

GNU_CONFIGURE=	yes
BUILD_TARGET=	shmux
TEST_TARGET=	test

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
