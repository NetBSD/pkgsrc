# $NetBSD: Makefile,v 1.4 2004/12/06 17:33:05 agc Exp $
#

DISTNAME=		gkrellm-est-20040710
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://cubidou.nerim.net/gkrellm-est/

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://cubidou.nerim.net/gkrellm-est/
COMMENT=		GKrellM plugin that controls EST-capable processors

USE_BUILDLINK3=		yes
NO_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	NetBSD-2.0[F-Z]*-i386 NetBSD-2.99.*-i386
ONLY_FOR_PLATFORM+=	NetBSD-[3-9].*-i386

do-install:
	${INSTALL_DATA} ${WRKSRC}/gkrellm-est.so ${PREFIX}/lib/gkrellm2/plugins

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
