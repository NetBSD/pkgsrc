# $NetBSD: Makefile,v 1.7 2015/08/17 17:11:29 wiz Exp $
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

.include "../../mk/bsd.prefs.mk"

# libtinfo in DragonFly is linked with libncurses
.if ${OPSYS} == "DragonFly"
BUILDLINK_TRANSFORM+=	rm:-ltinfo
.endif

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
