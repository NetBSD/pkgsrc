# $NetBSD: Makefile,v 1.6 2004/12/03 15:15:10 wiz Exp $

DISTNAME=	shmux-1.0b5
CATEGORIES=	sysutils
MASTER_SITES=	http://web.taranis.org/shmux/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://web.taranis.org/shmux/
COMMENT=	Shell Multiplexor

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
BUILD_TARGET=	shmux
TEST_TARGET=	test

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
