# $NetBSD: Makefile,v 1.7 2020/06/14 10:21:10 nia Exp $

DISTNAME=	libtelnet-0.23
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=seanmiddleditch/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seanmiddleditch/libtelnet
COMMENT=	RFC-complient TELNET implementation as a C library
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

# __EXTENSIONS__ needed by patch-util_telnet-client.c
CPPFLAGS.SunOS+=	-D__EXTENSIONS__
LIBS.SunOS+=		-lnsl -lsocket

PKGCONFIG_OVERRIDE+=	libtelnet.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
