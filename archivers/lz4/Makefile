# $NetBSD: Makefile,v 1.5 2015/06/09 12:04:19 fhajny Exp $

DISTNAME=	lz4-r130
PKGNAME=	${DISTNAME:S/-r/-/}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cyan4973/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://code.google.com/p/lz4/
COMMENT=	Extremely Fast Compression algorithm
LICENSE=	2-clause-bsd

GITHUB_TAG=	r${PKGVERSION_NOREV}

USE_LANGUAGES=	c c99
USE_TOOLS+=	gmake pkg-config

CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=600

PKGCONFIG_OVERRIDE+=	liblz4.pc.in

.include "../../mk/bsd.pkg.mk"
