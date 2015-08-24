# $NetBSD: Makefile,v 1.6 2015/08/24 16:28:32 fhajny Exp $

DISTNAME=	lz4-r131
PKGNAME=	${DISTNAME:S/-r/-/}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cyan4973/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/Cyan4973/lz4/
COMMENT=	Extremely Fast Compression algorithm
LICENSE=	2-clause-bsd

GITHUB_TAG=	r${PKGVERSION_NOREV}

USE_LANGUAGES=	c c99
USE_TOOLS+=	gmake pkg-config

CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=600

PKGCONFIG_OVERRIDE+=	liblz4.pc.in

.include "../../mk/bsd.pkg.mk"
