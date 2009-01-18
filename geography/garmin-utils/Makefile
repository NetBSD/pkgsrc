# $NetBSD: Makefile,v 1.7.2.1 2009/01/18 12:03:39 rtr Exp $
#

DISTNAME=		garmin-utils-2.4
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.snafu.org/pub/

MAINTAINER=		gson@NetBSD.org
HOMEPAGE=		http://www.snafu.org/
COMMENT=		Utilities for Garmin GPS receivers

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	NetBSD-*-* Linux-*-*

INSTALLATION_DIRS=	bin lib ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.prefs.mk"

CPPFLAGS.Linux=		-DLINUX

.if ${OPSYS} == "Linux"
MAKE_FLAGS+=	SIO_TYPE=-DSIO_TYPE=Linux GPG_SERIAL_PORT=/dev/gps \
		NEEDS_STRLCPY=1
.endif

.include "../../mk/bsd.pkg.mk"
