# $NetBSD: Makefile,v 1.18 2021/04/23 22:25:03 wiz Exp $

DISTNAME=	ccze-0.2.1
PKGREVISION=	4
CATEGORIES=	sysutils
#MASTER_SITES=	ftp://bonehunter.rulez.org/pub/ccze/stable/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bonehunter.rulez.org/software/ccze/
COMMENT=	Log coloriser, fast and light on resources

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
BUILDLINK_TRANSFORM+=	rm:-Wmulticharacter

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
