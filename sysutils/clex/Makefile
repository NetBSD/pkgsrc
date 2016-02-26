# $NetBSD: Makefile,v 1.8 2016/02/26 10:24:11 jperkin Exp $
#

DISTNAME=		clex-4.6.4
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.clex.sk/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.clex.sk/
COMMENT=		File manager with a full-screen user interface
LICENSE=		gnu-gpl-v2

USE_NCURSES=		yes # enter_{bold,reverse,underline}_mode
GNU_CONFIGURE=		yes

# for easy to maintain patches
post-extract:
	cd ${WRKSRC} && ${RM} -f src/*.orig

# libtinfo in DragonFly is linked with libncurses
BUILDLINK_TRANSFORM.DragonFly+=	rm:-ltinfo

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
