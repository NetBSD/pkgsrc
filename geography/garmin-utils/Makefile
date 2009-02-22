# $NetBSD: Makefile,v 1.12 2009/02/22 22:07:52 gdt Exp $
#

DISTNAME=		garmin-utils-2.5
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.snafu.org/pub/

MAINTAINER=		gson@NetBSD.org
# also gdt@NetBSD.org is helping
HOMEPAGE=		http://www.snafu.org/
COMMENT=		Utilities for Garmin GPS receivers

PKG_DESTDIR_SUPPORT=	user-destdir

# This seems excessive; on other ones it can be made to work.
ONLY_FOR_PLATFORM=	NetBSD-*-* Linux-*-*

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
