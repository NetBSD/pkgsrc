# $NetBSD: Makefile,v 1.14 2012/10/04 09:19:17 asau Exp $
#

DISTNAME=		garmin-utils-2.5
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.snafu.org/pub/

MAINTAINER=		gson@NetBSD.org
# also gdt@NetBSD.org is helping
HOMEPAGE=		http://www.snafu.org/
COMMENT=		Utilities for Garmin GPS receivers

INSTALLATION_DIRS=	bin lib ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

USE_BSD_MAKEFILE=	yes

MAKE_JOBS_SAFE=		no

# No actual serial port will be right for any significant number of users,
# so make everyone use a symlink.
MAKE_FLAGS+=		GPS_SERIAL_PORT=/dev/gps

.include "../../mk/bsd.prefs.mk"

CPPFLAGS.Linux=		-DLINUX

.if ${OPSYS} == "Linux"
MAKE_FLAGS+=	SIO_TYPE=-DSIO_TYPE=Linux

# On Linux, libc apparently does not have strlcpy.
MAKE_FLAGS+=	NEEDS_STRLCPY=1
.endif

.include "../../mk/bsd.pkg.mk"
