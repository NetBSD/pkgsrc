# $NetBSD: Makefile,v 1.23 2024/01/30 18:29:20 adam Exp $

GITHUB_PROJECT=	riemann-c-client
GITHUB_TAG=	${DISTNAME}
DISTNAME=	riemann-c-client-1.10.4
PKGNAME=	${DISTNAME:S/c-//}
PKGREVISION=	16
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=algernon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/algernon/riemann-c-client/
COMMENT=	C client library for the Riemann monitoring system
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf gmake pkg-config

TEST_TARGET=	check

LDFLAGS.SunOS+=	-lsocket

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "options.mk"

.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
