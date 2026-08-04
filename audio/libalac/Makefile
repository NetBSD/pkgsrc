# $NetBSD: Makefile,v 1.4 2026/08/04 20:28:44 wiz Exp $
#

DISTNAME=	libalac-r3
PKGNAME=	libalac-0.0.20111026
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://alac.macosforge.org/
COMMENT=	Apple Lossless Audio Codec is an audio codec developed by Apple
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/libalac-r3/codec
USE_LANGUAGES=	c c++
MAKE_FILE=	makefile

USE_LIBTOOL=	yes

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
