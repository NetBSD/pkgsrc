# $NetBSD: Makefile,v 1.1 2018/02/12 19:33:43 minskim Exp $

CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://r-pbd.org/
COMMENT=	Interface to ZeroMQ
LICENSE=	gnu-gpl-v3

R_PKGNAME=	pbdZMQ
R_PKGVER=	0.3-2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config sed

CHECK_PORTABILITY_SKIP=	src/zmqsrc/configure

BUILDLINK_API_DEPENDS.R+=	R>=3.2.0
.include "../../math/R/Makefile.extension"
.include "../../net/zeromq/buildlink3.mk"

post-install:
	sed -e 's,PKG_CONFIG.*,PKG_CONFIG = ${LOCALBASE}/bin/pkg-config,' \
		${WRKSRC}/src/Makeconf > \
		${DESTDIR}${PREFIX}/lib/R/library/pbdZMQ/etc/Makeconf

.include "../../mk/bsd.pkg.mk"
