# $NetBSD: Makefile,v 1.7 2023/07/23 13:46:45 yhardy Exp $

DISTNAME=	ck-0.7.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=concurrencykit/}
GITHUB_PROJECT=	ck
GITHUB_TAG=	0.7.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://concurrencykit.org/
COMMENT=	Concurrency primitives, safe memory reclamation & non-blocking data structures
LICENSE=	2-clause-bsd

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

PKGCONFIG_OVERRIDE+=	build/ck.pc.in

.include "../../mk/bsd.pkg.mk"
