# $NetBSD: Makefile,v 1.8 2026/08/04 20:28:59 wiz Exp $

DISTNAME=	libbpg-0.9.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://bellard.org/bpg/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://bellard.org/bpg/
COMMENT=	Better Portable Graphics image format library
LICENSE=	modified-bsd

USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++

AUTO_MKDIRS=	yes

SUBST_CLASSES+=		config
SUBST_MESSAGE.config=	config.h file substitutions
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	config.h
SUBST_VARS.config=	PREFIX

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--gc-sections
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--gc-sections

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
