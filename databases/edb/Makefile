# $NetBSD: Makefile,v 1.18 2006/04/28 12:17:04 joerg Exp $
#

DISTNAME=		edb-1.0.3
PKGREVISION=		6
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.enlightenment.org/pages/components.html
COMMENT=		Database abstraction layer to Berkeley databases

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--enable-cxx

.include "../../x11/gtk/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
