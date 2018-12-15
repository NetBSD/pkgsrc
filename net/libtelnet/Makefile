# $NetBSD: Makefile,v 1.4 2018/12/15 21:12:22 wiz Exp $

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
# Needed on at least NetBSD for addrinfo
CPPLAGS+=		-D_XOPEN_SOURCE=520
LIBS.SunOS+=		-lnsl -lsocket

PKGCONFIG_OVERRIDE+=	libtelnet.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
