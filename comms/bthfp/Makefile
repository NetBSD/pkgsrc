# $NetBSD: Makefile,v 1.6 2009/05/12 14:36:28 plunky Exp $

DISTNAME=		bthfp-0.1
CATEGORIES=		comms
MASTER_SITES=		http://homepages.rya-online.net/plunky/
DISTFILES=		bthfp-0.1.tar.gz

MAINTAINER=		plunky@rya-online.net
COMMENT=		Bluetooth Handsfree Profile

LICENSE=		modified-bsd

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.prefs.mk"

# This uses the older ServiceDiscovery API
.if (${OPSYS} == "NetBSD" && \
    (!empty(OS_VERSION:M5.99.*) || !empty(OS_VERSION:M[6-9].*)))
MAKE_ENV+=	HAVE_LIBSDP=no
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bthfp ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bthfp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
