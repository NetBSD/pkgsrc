# $NetBSD: Makefile,v 1.31 2017/09/03 08:36:51 wiz Exp $

DISTNAME=		edb-1.0.5
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}
PKGREVISION=		5

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		https://www.enlightenment.org/Libraries/Edb/
COMMENT=		Database abstraction layer to Berkeley databases

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE=	edb.pc.in

CONFIGURE_ARGS+=	--enable-cxx --disable-gtk

INCOMPAT_CURSES+=	NetBSD-[0-4].*-*
FAKE_NCURSES=		yes

.include "../../mk/curses.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
