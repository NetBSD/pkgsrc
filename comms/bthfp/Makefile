# $NetBSD: Makefile,v 1.13 2024/05/20 12:39:04 gdt Exp $

DISTNAME=		bthfp-0.1
PKGREVISION=		1
CATEGORIES=		comms
MASTER_SITES=		https://www.NetBSD.org/~plunky/
DISTFILES=		bthfp-0.1.tar.gz

MAINTAINER=		plunky@NetBSD.org
COMMENT=		Bluetooth Handsfree Profile
LICENSE=		modified-bsd

ONLY_FOR_PLATFORM=	NetBSD-*-*
NOT_FOR_PLATFORM=	NetBSD-[0-3].*-*

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.prefs.mk"

# This uses the older ServiceDiscovery API
.if (${OPSYS} == "NetBSD" && \
    (!empty(OS_VERSION:M5.99.*) || !empty(OS_VERSION:M[6-9].*) || !empty(OS_VERSION:M[1-9][0-9].*)))
MAKE_ENV+=	HAVE_LIBSDP=no
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bthfp ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bthfp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
