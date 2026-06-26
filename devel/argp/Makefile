# $NetBSD: Makefile,v 1.13 2026/06/26 06:15:09 wiz Exp $

DISTNAME=	argp-standalone-1.5.0
PKGNAME=	${DISTNAME:S/-standalone//}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=argp-standalone/}
GITHUB_PROJECT=	argp-standalone

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/argp-standalone/argp-standalone
COMMENT=	Argument parsing function from glibc
LICENSE=	gnu-lgpl-v2.1

FORCE_C_STD=	gnu99

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
