# $NetBSD: Makefile,v 1.3 2013/05/04 10:37:38 dsainty Exp $
#

DISTNAME=		testdisk-6.13
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.cgsecurity.org/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.cgsecurity.org/wiki/TestDisk
COMMENT=		Tool to check and undelete partitions
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes

.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
