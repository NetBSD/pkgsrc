# $NetBSD: Makefile,v 1.1.1.1 2004/07/10 17:03:09 cube Exp $
#

DISTNAME=		gkrellm-est-20040710
CATEGORIES=		sysutils
MASTER_SITES=		http://cubidou.nerim.net/gkrellm-est/

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://cubidou.nerim.net/gkrellm-est/
COMMENT=		GKrellM plugin that controls EST-capable processors

USE_BUILDLINK3=		yes
NO_CONFIGURE=		yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/gkrellm-est.so ${PREFIX}/lib/gkrellm2/plugins

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
