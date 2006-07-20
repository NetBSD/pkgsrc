# $NetBSD: Makefile,v 1.20 2006/07/20 19:00:48 wiz Exp $
#

DISTNAME=		edb-1.0.5
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.enlightenment.org/Libraries/Edb/
COMMENT=		Database abstraction layer to Berkeley databases

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++
USE_NCURSES=		YES # putwin
PKGCONFIG_OVERRIDE=	edb.pc.in

CONFIGURE_ARGS+=	--enable-cxx

.include "../../x11/gtk/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
