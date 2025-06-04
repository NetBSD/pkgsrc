# $NetBSD: Makefile,v 1.2 2025/06/04 13:05:47 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=		${GITHUB_PROJECT}-0.2
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=elric1/}
GITHUB_PROJECT=		lnetd
GITHUB_TAG=		e0a8f304bffade91f2f8b9fb1e5e4b8cc2bd68d1

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://oskt.secure-endpoints.com/lnetd.html
COMMENT=		Utility to bind to UNIX domain socket and spawn children
LICENSE=		mit

LDFLAGS.SunOS+=		-lsocket

.include "../../mk/bsd.pkg.mk"
