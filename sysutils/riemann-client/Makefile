# $NetBSD: Makefile,v 1.26 2024/04/14 09:37:31 wiz Exp $

DISTNAME=	riemann-c-client-2.2.0
PKGNAME=	${DISTNAME:S/c-//}
CATEGORIES=	sysutils
MASTER_SITES=	https://git.madhouse-project.org/algernon/riemann-c-client/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.madhouse-project.org/algernon/riemann-c-client
COMMENT=	C client library for the Riemann monitoring system
LICENSE=	eupl-v1.2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf gmake pkg-config

WRKSRC=		${WRKDIR}/riemann-c-client

TEST_TARGET=	check

LDFLAGS.SunOS+=	-lsocket

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "options.mk"

.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
