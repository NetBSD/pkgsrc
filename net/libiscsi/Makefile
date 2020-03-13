# $NetBSD: Makefile,v 1.1 2020/03/13 13:21:39 tnn Exp $

DISTNAME=	libiscsi-1.19.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=sahlberg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sahlberg/libiscsi
COMMENT=	iscsi client library and utilities
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf automake autoreconf gmake pkg-config

PKGCONFIG_OVERRIDE+=	libiscsi.pc.in
BUILDLINK_TRANSFORM+=	rm:-Werror

pre-configure:
	cd ${WRKSRC} && autoreconf -if

.include "../../mk/bsd.pkg.mk"
