# $NetBSD: Makefile,v 1.10 2012/03/03 00:13:55 wiz Exp $

DISTNAME=	ccze-0.2.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://bonehunter.rulez.org/pub/ccze/stable/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bonehunter.rulez.org/software/ccze/
COMMENT=	Log coloriser, fast and light on resources

INCOMPAT_CURSES=	NetBSD-1.5*-* NetBSD-1.6*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
BUILDLINK_TRANSFORM+=	rm:-Wmulticharacter

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
