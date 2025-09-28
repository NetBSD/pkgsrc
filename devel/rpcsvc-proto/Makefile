# $NetBSD: Makefile,v 1.1 2025/09/28 16:25:06 bsiegert Exp $

DISTNAME=	rpcsvc-proto-1.4.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=thkukuk/rpcsvc-proto/releases/download/v${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/thkukuk/rpcsvc-proto/
COMMENT=	RPCSVC protocol definitions from glibc
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	Linux-*-*

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
