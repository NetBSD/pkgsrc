# $NetBSD: Makefile,v 1.8 2006/03/04 21:30:43 jlam Exp $

DISTNAME=	shmux-1.0b5
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
.include "../../mk/bsd.pkg.mk"
