# $NetBSD: Makefile,v 1.11 2012/01/08 03:48:27 sbd Exp $

DISTNAME=	shmux-1.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://web.taranis.org/shmux/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.taranis.org/shmux/
COMMENT=	Shell Multiplexor

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
BUILD_TARGET=	shmux
TEST_TARGET=	test

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
