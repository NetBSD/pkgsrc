# $NetBSD: Makefile,v 1.4 1999/08/29 15:29:40 jlam Exp $
#

DISTNAME=		latestCDK
PKGNAME=		cdk-4.9.9
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		devel
MASTER_SITES=		http://www.vexus.ca/release/
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.vexus.ca/CDK.html

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoconf:../../devel/autoconf
DEPENDS+=		ncurses-4.2:../../devel/ncurses

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include	# for ncurses.h
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

ALL_TARGET=		default

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cdk
	for file in ${WRKSRC}/examples/*.c ${WRKSRC}/examples/Makefile; do \
		${INSTALL_DATA} $${file} ${PREFIX}/share/examples/cdk/; \
	done

.include "../../mk/bsd.pkg.mk"
