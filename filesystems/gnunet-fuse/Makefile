# $NetBSD: Makefile,v 1.24 2026/05/14 16:40:54 ryoon Exp $

DISTNAME=		gnunet-fuse-0.21.0
PKGREVISION=		15
CATEGORIES=		filesystems
MASTER_SITES=		${MASTER_SITE_GNU:=gnunet/}

MAINTAINER=		nikita@NetBSD.org
HOMEPAGE=		https://gnunet.org/
COMMENT=		GNUnet FUSE extension
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS=		pkg-config
USE_LANGUAGES=		c

PTHREAD_OPTS=		require native
LDFLAGS+=		-lpthread

.include "../../net/gnunet/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
