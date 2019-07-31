# $NetBSD: Makefile,v 1.3 2019/07/31 20:44:35 brook Exp $

CATEGORIES=	net R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://r-pbd.org/
COMMENT=	Interface to ZeroMQ
LICENSE=	gnu-gpl-v3

R_PKGNAME=	pbdZMQ
R_PKGVER=	0.3-3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config sed

CHECK_PORTABILITY_SKIP=	src/zmqsrc/configure

post-install:
	${SED} -e 's,PKG_CONFIG.*,PKG_CONFIG = ${PREFIX}/bin/pkg-config,' \
		${WRKSRC}/src/Makeconf > \
		${DESTDIR}${PREFIX}/lib/R/library/pbdZMQ/etc/Makeconf

.include "../../math/R/Makefile.extension"
.include "../../net/zeromq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
