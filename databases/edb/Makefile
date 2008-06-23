# $NetBSD: Makefile,v 1.22 2008/06/23 16:14:34 joerg Exp $
#

DISTNAME=		edb-1.0.5
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}
PKGREVISION=		1

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.enlightenment.org/Libraries/Edb/
COMMENT=		Database abstraction layer to Berkeley databases

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++
USE_NCURSES=		YES # putwin
PKGCONFIG_OVERRIDE=	edb.pc.in

CONFIGURE_ARGS+=	--enable-cxx

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
