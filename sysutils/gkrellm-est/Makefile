# $NetBSD: Makefile,v 1.3 2004/10/03 00:18:15 tv Exp $
#

DISTNAME=		gkrellm-est-20040710
PKGREVISION=	1
CATEGORIES=		sysutils
MASTER_SITES=		http://cubidou.nerim.net/gkrellm-est/

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://cubidou.nerim.net/gkrellm-est/
COMMENT=		GKrellM plugin that controls EST-capable processors

USE_BUILDLINK3=		yes
NO_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	NetBSD-2.0[F-Z]*-i386

do-install:
	${INSTALL_DATA} ${WRKSRC}/gkrellm-est.so ${PREFIX}/lib/gkrellm2/plugins

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
