# $NetBSD: Makefile,v 1.26 2026/02/16 12:45:23 adam Exp $

DISTNAME=	pgpdump-0.37
CATEGORIES=	security
MASTER_SITES=	http://www.mew.org/~kazu/proj/pgpdump/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	https://www.mew.org/~kazu/proj/pgpdump/en/
COMMENT=	PGP packet visualizer
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
TEST_TARGET=	check

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
