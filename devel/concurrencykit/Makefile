# $NetBSD: Makefile,v 1.10 2026/05/11 07:26:05 adam Exp $

DISTNAME=	ck-0.7.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=concurrencykit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://concurrencykit.org/
COMMENT=	Concurrency primitives and building blocks for high performance apps
LICENSE=	2-clause-bsd

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
PKGCONFIG_OVERRIDE+=	build/ck.pc.in

.include "../../mk/bsd.pkg.mk"
