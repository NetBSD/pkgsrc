# $NetBSD: Makefile,v 1.24 2012/10/02 21:25:17 asau Exp $
#

DISTNAME=		edb-1.0.5
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}
PKGREVISION=		1

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.enlightenment.org/Libraries/Edb/
COMMENT=		Database abstraction layer to Berkeley databases

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++
USE_NCURSES=		YES # putwin
PKGCONFIG_OVERRIDE=	edb.pc.in

CONFIGURE_ARGS+=	--enable-cxx --disable-gtk

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
