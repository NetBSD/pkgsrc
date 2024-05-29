# $NetBSD: Makefile,v 1.68 2024/05/29 16:34:25 adam Exp $

DISTNAME=		gkrellm-est-20040710
PKGREVISION=		55
CATEGORIES=		sysutils
#MASTER_SITES=		http://cubidou.nerim.net/gkrellm-est/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://cubidou.nerim.net/gkrellm-est/
COMMENT=		GKrellM plugin that controls EST-capable processors

NO_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

ONLY_FOR_PLATFORM=	NetBSD-2.0[F-Z]*-i386 NetBSD-2.99.*-i386
ONLY_FOR_PLATFORM+=	NetBSD-[3-9].*-i386

INSTALLATION_DIRS=	lib/gkrellm2/plugins

do-install:
	${INSTALL_DATA} ${WRKSRC}/gkrellm-est.so ${DESTDIR}${PREFIX}/lib/gkrellm2/plugins

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
