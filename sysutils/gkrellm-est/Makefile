# $NetBSD: Makefile,v 1.27 2012/09/15 10:06:23 obache Exp $
#

DISTNAME=		gkrellm-est-20040710
PKGREVISION=		17
CATEGORIES=		sysutils
MASTER_SITES=		http://cubidou.nerim.net/gkrellm-est/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://cubidou.nerim.net/gkrellm-est/
COMMENT=		GKrellM plugin that controls EST-capable processors

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

ONLY_FOR_PLATFORM=	NetBSD-2.0[F-Z]*-i386 NetBSD-2.99.*-i386
ONLY_FOR_PLATFORM+=	NetBSD-[3-9].*-i386
ONLY_FOR_PLATFORM+=	DragonFly-1.[7-9].*-i386 DragonFly-[2-9].*-i386

INSTALLATION_DIRS=	lib/gkrellm2/plugins

do-install:
	${INSTALL_DATA} ${WRKSRC}/gkrellm-est.so ${DESTDIR}${PREFIX}/lib/gkrellm2/plugins

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
