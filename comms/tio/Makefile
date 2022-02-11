# $NetBSD: Makefile,v 1.2 2022/02/11 12:14:20 fcambus Exp $

DISTNAME=	tio-1.32
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=tio/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/tio/tio
COMMENT=	Simple TTY terminal I/O application
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
CHECK_PORTABILITY_SKIP+= configure

.include "../../mk/bsd.pkg.mk"
