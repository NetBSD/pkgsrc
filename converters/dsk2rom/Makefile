# $NetBSD: Makefile,v 1.1 2018/08/13 15:53:49 nia Exp $

DISTNAME=	dsk2rom-0.80
CATEGORIES=	converters
MASTER_SITES=	http://home.kabelfoon.nl/~vincentd/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.kabelfoon.nl/~vincentd/
COMMENT=	MSX disk image conversion utility
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/dsk2rom

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
MAKE_FLAGS+=	NATIVE_CC=${NATIVE_CC:Q}
.else
MAKE_FLAGS+=	NATIVE_CC=${CC:Q}
.endif

INSTALLATION_DIRS+=	${PREFIX}/bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dsk2rom ${DESTDIR}${PREFIX}/bin/dsk2rom

.include "../../mk/bsd.pkg.mk"
