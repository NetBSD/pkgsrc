# $NetBSD: Makefile,v 1.1 2015/09/06 06:50:52 kardel Exp $

PKGNAME=		hytctl-1.0
CATEGORIES=		sysutils
ONLY_FOR_PLATFORM=      NetBSD-*-*

MAINTAINER=		kardel@NetBSD.org
COMMENT=		Admin tool to read/write HYT 221/271/939 device EEPROM values
LICENSE=		modified-bsd

USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

.include "../../mk/bsd.prefs.mk"

do-extract:
	${CP} -R ${FILESDIR}/sbin ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
