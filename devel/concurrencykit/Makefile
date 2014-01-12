# $NetBSD: Makefile,v 1.1 2014/01/12 14:59:47 mspo Exp $

DISTNAME=	ck-0.3.3
CATEGORIES=	devel
MASTER_SITES=	http://concurrencykit.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://concurrencykit.org/
COMMENT=	Concurrency primitives, safe memory reclamation mechanisms and non-blocking data structures
LICENSE=	2-clause-bsd

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	build/ck.pc.in

.include "../../mk/bsd.pkg.mk"
