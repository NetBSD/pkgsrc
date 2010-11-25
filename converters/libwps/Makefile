# $NetBSD: Makefile,v 1.2 2010/11/25 10:28:34 wiz Exp $

DISTNAME=	libwps-0.1.2
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwps/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libwps.sourceforge.net/
COMMENT=	Library for importing Microsoft Works documents
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-docs
PKGCONFIG_OVERRIDE+=	libwps-0.1.pc.in libwps-stream-0.1.pc.in

.include "../../converters/libwpd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
