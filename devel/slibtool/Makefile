# $NetBSD: Makefile,v 1.10 2024/07/04 21:30:48 cheusov Exp $

DISTNAME=	slibtool-0.5.34
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=midipix-project/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://midipix.org/
COMMENT=	Surrogate libtool implementation, written in C
LICENSE=	mit

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	gmake m4
CFLAGS.SunOS+=	-D__EXTENSIONS__
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

.include "../../mk/bsd.pkg.mk"
