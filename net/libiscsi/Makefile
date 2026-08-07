# $NetBSD: Makefile,v 1.3 2026/08/07 08:14:44 adam Exp $

DISTNAME=	libiscsi-1.20.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=sahlberg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sahlberg/libiscsi
COMMENT=	iscsi client library and utilities
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf automake autoreconf gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-werror
PKGCONFIG_OVERRIDE+=	libiscsi.pc.in

LIBS.NetBSD+=	-lpthread -lrt

pre-configure:
	cd ${WRKSRC} && autoreconf -if

.include "../../mk/bsd.pkg.mk"
