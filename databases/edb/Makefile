# $NetBSD: Makefile,v 1.13 2004/10/03 00:13:18 tv Exp $
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
USE_GCC_SHLIB=		YES

CONFIGURE_ARGS+=	--enable-cxx

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
