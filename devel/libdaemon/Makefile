# $NetBSD: Makefile,v 1.9 2020/04/26 09:55:09 rillig Exp $
#

DISTNAME=		libdaemon-0.14
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://0pointer.de/lennart/projects/libdaemon/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://0pointer.de/lennart/projects/libdaemon/
COMMENT=		C library that eases the writing of UNIX daemons
LICENSE=		gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE+=	pkgconfig/libdaemon.pc.in
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-lynx

INSTALLATION_DIRS=	share/doc/libdaemon

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DESTDIR}${PREFIX}/share/doc/libdaemon

.include "../../mk/bsd.pkg.mk"

.if (${OPSYS} == "NetBSD" && ${OS_VERSION:M4.*} != "") || (${OPSYS} == "OpenBSD")
BUILDLINK_TRANSFORM+=	rm:-Wl,--no-undefined
.endif
