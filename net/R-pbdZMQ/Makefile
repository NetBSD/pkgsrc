# $NetBSD: Makefile,v 1.6 2024/12/14 00:43:57 mef Exp $

R_PKGNAME=	pbdZMQ
R_PKGVER=	0.3-13
CATEGORIES=	net

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Interface to ZeroMQ
LICENSE=	gnu-gpl-v3

TEST_DEPENDS+=	tex-amscls-[0-9]*:../../print/tex-amscls
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
TEST_DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config sed

CHECK_PORTABILITY_SKIP=	src/zmqsrc/configure

post-install:
	${SED} -e 's,PKG_CONFIG.*,PKG_CONFIG = ${PREFIX}/bin/pkg-config,' \
		${WRKSRC}/src/Makeconf > \
		${DESTDIR}${PREFIX}/lib/R/library/pbdZMQ/etc/Makeconf

.include "../../math/R/Makefile.extension"
.include "../../net/zeromq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
