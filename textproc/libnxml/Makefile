# $NetBSD: Makefile,v 1.35 2024/05/29 16:34:37 adam Exp $
#

DISTNAME=	libnxml-0.18.3
PKGREVISION=	31
CATEGORIES=	textproc
MASTER_SITES=	http://www.autistici.org/bakunin/libnxml/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://www.autistici.org/bakunin/libnxml/doc/
COMMENT=	C library for parsing, writing and creating XML files or streams
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	nxml.pc.in

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
