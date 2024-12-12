# $NetBSD: Makefile,v 1.1 2024/12/12 15:51:39 ryoon Exp $

PKGNAME=	dps8m-${VER}
DISTNAME=	dps8m-r${VER}-src
CATEGORIES=	emulators
MASTER_SITES=	https://dps8m.gitlab.io/dps8m-r${VER}-archive/R${VER}/
EXTRACT_SUFX=	.tar.lz

VER=		3.0.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dps8m.gitlab.io/dps8m/
COMMENT=	DPS-8/M mainframe simulator
LICENSE=	icu

WRKSRC=		${WRKDIR}/dps8

USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

LDFLAGS.NetBSD+=     -lm

.include "../../devel/libuv/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
