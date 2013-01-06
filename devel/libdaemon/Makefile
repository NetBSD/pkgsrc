# $NetBSD: Makefile,v 1.8 2013/01/06 03:32:34 ryoon Exp $
#

DISTNAME=		libdaemon-0.14
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://0pointer.de/lennart/projects/libdaemon/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://0pointer.de/lennart/projects/libdaemon/
COMMENT=		C library that eases the writing of UNIX daemons
LICENSE=		gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libdaemon.pc.in
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-lynx

INSTALLATION_DIRS=	share/doc/libdaemon

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DESTDIR}${PREFIX}/share/doc/libdaemon

.include "../../mk/bsd.pkg.mk"

.if (${OPSYS} == "NetBSD" && ${OS_VERSION:M4.*} != "") || (${OPSYS} == "OpenBSD")
BUILDLINK_TRANSFORM+=	rm:-Wl,--no-undefined
.endif
