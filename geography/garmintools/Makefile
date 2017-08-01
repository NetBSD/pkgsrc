# $NetBSD: Makefile,v 1.4 2017/08/01 17:03:25 wiz Exp $

DISTNAME=		garmintools-0.10
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

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
