# $NetBSD: Makefile,v 1.11 2004/02/14 17:21:35 jlam Exp $
#

DISTNAME=		edb-1.0.3
PKGREVISION=		3
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.enlightenment.org/pages/components.html
COMMENT=		Database abstraction layer to Berkeley databases

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES
USE_GCC_SHLIB=		YES

CONFIGURE_ARGS+=	--enable-cxx

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
