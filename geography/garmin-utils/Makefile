# $NetBSD: Makefile,v 1.15 2016/02/25 13:22:00 jperkin Exp $
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

CPPFLAGS.Linux=		-DLINUX

OPSYSVARS+=		MAKE_FLAGS
MAKE_FLAGS.Linux+=	SIO_TYPE=-DSIO_TYPE=Linux
# On Linux, libc apparently does not have strlcpy.
MAKE_FLAGS.Linux+=	NEEDS_STRLCPY=1

.include "../../mk/bsd.pkg.mk"
