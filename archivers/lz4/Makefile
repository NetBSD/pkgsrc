# $NetBSD: Makefile,v 1.3 2014/12/12 11:20:56 fhajny Exp $

DISTNAME=	lz4-r124
PKGNAME=	${DISTNAME:S/-r/-/}
CATEGORIES=	archivers
MASTER_SITES=	-https://github.com/Cyan4973/lz4/archive/${DISTNAME:S/lz4-//}${EXTRACT_SUFX}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://code.google.com/p/lz4/
COMMENT=	Extremely Fast Compression algorithm
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c99
USE_TOOLS+=	gmake pkg-config

CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=600

PKGCONFIG_OVERRIDE+=	liblz4.pc.in

.include "../../mk/bsd.pkg.mk"
