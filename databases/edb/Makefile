# $NetBSD: Makefile,v 1.14 2004/11/13 22:04:52 jlam Exp $
#

DISTNAME=		edb-1.0.3
PKGREVISION=		4
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.enlightenment.org/pages/components.html
COMMENT=		Database abstraction layer to Berkeley databases

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES
USE_LANGUAGE=		c c++

CONFIGURE_ARGS+=	--enable-cxx

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
