# $NetBSD: Makefile,v 1.3 2016/08/10 23:44:10 mef Exp $

DISTNAME=	ck-0.5.1
CATEGORIES=	devel
MASTER_SITES=	http://concurrencykit.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://concurrencykit.org/
COMMENT=	Concurrency primitives, safe memory reclamation & non-blocking data structures
LICENSE=	2-clause-bsd

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	build/ck.pc.in

.include "../../mk/bsd.pkg.mk"
