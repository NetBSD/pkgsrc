# $NetBSD: Makefile,v 1.16 2002/08/26 18:28:20 jlam Exp $
#

DISTNAME=		latestCDK
PKGNAME=		cdk-4.9.9
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		devel
MASTER_SITES=		http://www.vexus.ca/release/
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.vexus.ca/CDK.html
COMMENT=		Curses Development Kit

BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf

USE_BUILDLINK2=		yes
USE_NCURSES=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

ALL_TARGET=		default

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cdk
	for file in ${WRKSRC}/examples/*.c ${WRKSRC}/examples/Makefile; do \
		${INSTALL_DATA} $${file} ${PREFIX}/share/examples/cdk/; \
	done

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
