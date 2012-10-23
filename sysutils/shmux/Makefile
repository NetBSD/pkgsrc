# $NetBSD: Makefile,v 1.13 2012/10/23 19:51:23 asau Exp $

DISTNAME=	shmux-1.0
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://web.taranis.org/shmux/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.taranis.org/shmux/
COMMENT=	Shell Multiplexor

GNU_CONFIGURE=	yes
BUILD_TARGET=	shmux
TEST_TARGET=	test

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
