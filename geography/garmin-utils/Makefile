# $NetBSD: Makefile,v 1.11 2009/02/22 20:57:25 gdt Exp $
#

DISTNAME=		garmin-utils-2.5
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.snafu.org/pub/

MAINTAINER=		gson@NetBSD.org
HOMEPAGE=		http://www.snafu.org/
COMMENT=		Utilities for Garmin GPS receivers

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	NetBSD-*-* Linux-*-*

INSTALLATION_DIRS=	bin lib ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

USE_BSD_MAKEFILE=	yes

# No actual serial port will be right for any significant number of users,
# so make everyone use a symlink.
MAKE_FLAGS+=		GPS_SERIAL_PORT=/dev/gps

MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

CPPFLAGS.Linux=		-DLINUX

.if ${OPSYS} == "Linux"
MAKE_FLAGS+=	SIO_TYPE=-DSIO_TYPE=Linux \
		NEEDS_STRLCPY=1
.endif

.include "../../mk/bsd.pkg.mk"
