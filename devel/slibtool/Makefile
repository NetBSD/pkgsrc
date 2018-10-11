# $NetBSD: Makefile,v 1.7 2018/10/11 20:03:45 wiedi Exp $

DISTNAME=	slibtool-0.5.25
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

.include "../../mk/bsd.pkg.mk"
