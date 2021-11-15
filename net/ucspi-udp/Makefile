# $NetBSD: Makefile,v 1.1 2021/11/15 10:08:17 schmonz Exp $

GITHUB_PROJECT=	tsi-ucspi-udp
GITHUB_TAG=	ea972137e1da3189237aecc954bff2377398cb36
DISTNAME=	ea972137e1da3189237aecc954bff2377398cb36
PKGNAME=	ucspi-udp-0.88.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=tempestsecurity/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/tempestsecurity/tsi-ucspi-udp/
COMMENT=	Unix Client-Server interface utilities for UDP
LICENSE=	public-domain

MAKE_JOBS_SAFE=	no

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
