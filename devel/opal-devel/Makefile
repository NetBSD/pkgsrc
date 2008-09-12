# $NetBSD: Makefile,v 1.1.1.1 2008/09/12 13:22:05 jmcneill Exp $
#

DISTNAME=		opal-snapshot-20080907
PKGNAME=		opal-3.3.0.20080907
CATEGORIES=		devel net comms
MASTER_SITES=		http://snapshots.ekiga.net/snapshots/sources/archives/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ekiga.net/
COMMENT=		Open Phone Abstraction Library

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BUILD_TARGET=		opt

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/opal

post-install:
	${INSTALL_DATA} ${WRKSRC}/version.h ${PREFIX}/share/opal

.include "../../devel/ptlib/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
#.include "../../multimedia/ffmpeg/buildlink3.mk"
#.include "../../multimedia/x264-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
