# $NetBSD: Makefile,v 1.9 2025/12/28 12:13:01 yhardy Exp $

DISTNAME=	ck-0.7.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=concurrencykit/}
GITHUB_PROJECT=	ck
GITHUB_TAG=	0.7.2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://concurrencykit.org/
COMMENT=	Concurrency primitives, safe memory reclamation & non-blocking data structures
LICENSE=	2-clause-bsd

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

PKGCONFIG_OVERRIDE+=	build/ck.pc.in

.include "../../mk/bsd.pkg.mk"
