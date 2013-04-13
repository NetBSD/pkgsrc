# $NetBSD: Makefile,v 1.3 2013/04/13 07:55:04 ghen Exp $

DISTNAME=		garmintools-0.10
CATEGORIES=		geography
MASTER_SITES=		http://garmintools.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://code.google.com/p/garmintools/
COMMENT=		Utilities for Garmin Forerunner 305 and similar GPS units

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

INSTALLATION_DIRS=	share/doc/garmintools

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/garmintools/

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
