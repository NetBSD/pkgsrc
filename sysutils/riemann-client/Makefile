# $NetBSD: Makefile,v 1.2 2018/01/17 12:10:38 jperkin Exp $

DISTNAME=	riemann-c-client-1.9.1
PKGNAME=	${DISTNAME:S/c-//}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=algernon/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/algernon/riemann-c-client/
COMMENT=	C client library for the Riemann monitoring system
LICENSE=	gnu-lgpl-v3

GITHUB_PROJECT=	riemann-c-client
GITHUB_RELEASE=	${DISTNAME}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

.include "options.mk"

.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
