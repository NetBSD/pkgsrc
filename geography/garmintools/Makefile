# $NetBSD: Makefile,v 1.6 2018/02/27 23:56:09 khorben Exp $

DISTNAME=		garmintools-0.10
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		http://garmintools.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://code.google.com/archive/p/garmintools/
COMMENT=		Utilities for Garmin Forerunner 305 and similar GPS units
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

INSTALLATION_DIRS=	share/doc/garmintools

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/garmintools/

.include "../../mk/libusb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
