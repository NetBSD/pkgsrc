# $NetBSD: Makefile,v 1.5 2019/03/20 16:02:10 jperkin Exp $

DISTNAME=	libtelnet-0.21
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=seanmiddleditch/}

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	https://github.com/seanmiddleditch/libtelnet/
COMMENT=	RFC-complient TELNET implementation as a C library
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake pkg-config
GNU_CONFIGURE=	yes

# __EXTENSIONS__ needed by patch-util_telnet-client.c
CPPFLAGS.SunOS+=	-D__EXTENSIONS__
LIBS.SunOS+=		-lnsl -lsocket

PKGCONFIG_OVERRIDE+=	libtelnet.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
