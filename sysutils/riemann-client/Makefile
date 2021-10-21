# $NetBSD: Makefile,v 1.12 2021/10/21 20:33:08 kim Exp $

GITHUB_PROJECT=	riemann-c-client
GITHUB_TAG=	${DISTNAME}
DISTNAME=	riemann-c-client-1.10.4
PKGNAME=	${DISTNAME:S/c-//}
PKGREVISION=	6
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
.include "../../mk/bsd.pkg.mk"
