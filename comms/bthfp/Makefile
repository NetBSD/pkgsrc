# $NetBSD: Makefile,v 1.4 2009/05/07 17:59:37 plunky Exp $

DISTNAME=		bthfp-0.1
CATEGORIES=		comms
MASTER_SITES=		http://homepages.rya-online.net/plunky/
DISTFILES=		bthfp-0.1.tar.gz

MAINTAINER=		plunky@rya-online.net
COMMENT=		Bluetooth Handsfree Profile

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

USE_BSD_MAKEFILE=	yes

# (work in progress) make sure it uses old SDP API
CPPFLAGS+=	-DSDP_COMPAT

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bthfp ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bthfp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
