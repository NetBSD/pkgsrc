# $NetBSD: Makefile,v 1.29 2006/10/04 21:35:58 wiz Exp $
#

DISTNAME=		latestCDK
PKGNAME=		cdk-4.9.9
PKGREVISION=				2
CATEGORIES=		devel
MASTER_SITES=		http://www.vexus.ca/release/
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.vexus.ca/products/CDK/
COMMENT=		Curses Development Kit

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_NCURSES=		# uses ncurses internals
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf213

BUILD_TARGET=		default

pre-configure:
	cd ${WRKSRC}; autoconf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cdk
	for file in ${WRKSRC}/examples/*.c ${WRKSRC}/examples/Makefile; do \
		${INSTALL_DATA} $${file} ${PREFIX}/share/examples/cdk/; \
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
