# $NetBSD: Makefile,v 1.2 2009/02/07 17:51:59 joerg Exp $
#

DISTNAME=		libdaemon-0.12
CATEGORIES=		devel
MASTER_SITES=		http://0pointer.de/lennart/projects/libdaemon/

MAINTAINER=		adrianp@NetBSD.org
HOMEPAGE=		http://0pointer.de/lennart/projects/libdaemon/
COMMENT=		C library that eases the writing of UNIX daemons

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libdaemon.pc.in
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-lynx

INSTALLATION_DIRS=	share/doc/libdaemon

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DESTDIR}${PREFIX}/share/doc/libdaemon

.include "../../mk/bsd.pkg.mk"
