# $NetBSD: Makefile,v 1.82 2024/12/27 08:20:30 wiz Exp $
#

DISTNAME=		urlgfe-1.0.1
PKGREVISION=		75
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=urlget/}

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://urlget.sourceforge.net/
COMMENT=		Download manager for X

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../devel/pcre/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
