# $NetBSD: Makefile,v 1.29 2012/10/06 11:55:01 asau Exp $
#

DISTNAME=	xmahjongg-3.7
PKGNAME=	${DISTNAME}0
CATEGORIES=	games x11
MASTER_SITES=	http://www.lcdf.org/~eddietwo/xmahjongg/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.lcdf.org/~eddietwo/xmahjongg/
COMMENT=	The Chinese game of Mah Jongg for X11

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"
# XXX: hack - work round an ICE with GCC 3.3 on sparc
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "sparc"
GCC_REQD+=		3.4
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
