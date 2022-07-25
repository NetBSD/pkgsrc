# $NetBSD: Makefile,v 1.5 2022/07/25 11:12:21 wiz Exp $

DISTNAME=	ck-0.5.1
CATEGORIES=	devel
MASTER_SITES=	http://concurrencykit.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://concurrencykit.org/
COMMENT=	Concurrency primitives, safe memory reclamation & non-blocking data structures
LICENSE=	2-clause-bsd

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

PKGCONFIG_OVERRIDE+=	build/ck.pc.in

.include "../../mk/bsd.pkg.mk"
