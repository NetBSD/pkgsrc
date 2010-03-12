# $NetBSD: Makefile,v 1.1.1.1 2010/03/12 15:55:40 ghen Exp $

DISTNAME=		garmintools-0.10
CATEGORIES=		geography
MASTER_SITES=		http://garmintools.googlecode.com/files/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://code.google.com/p/garmintools/
COMMENT=		Utilities for Garmin Forerunner 305 and similar GPS units

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	share/doc/garmintools

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/garmintools/

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
