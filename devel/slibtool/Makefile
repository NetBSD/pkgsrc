# $NetBSD: Makefile,v 1.9 2023/08/02 16:30:56 nia Exp $

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
USE_TOOLS+=	gmake
CFLAGS.SunOS+=	-D__EXTENSIONS__
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

.include "../../mk/bsd.pkg.mk"
