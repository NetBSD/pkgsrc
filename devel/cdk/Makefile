# $NetBSD: Makefile,v 1.21 2003/09/27 17:07:35 grant Exp $
#

DISTNAME=		latestCDK
PKGNAME=		cdk-4.9.9
PKGREVISION=				1
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=		devel
MASTER_SITES=		http://www.vexus.ca/release/
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.vexus.ca/CDK.html
COMMENT=		Curses Development Kit

USE_BUILDLINK2=		yes
USE_NCURSES=		# uses ncurses internals
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
AUTOCONF_REQD=		2.13

ALL_TARGET=		default

pre-configure:
	cd ${WRKSRC}; ${AUTOCONF}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cdk
	for file in ${WRKSRC}/examples/*.c ${WRKSRC}/examples/Makefile; do \
		${INSTALL_DATA} $${file} ${PREFIX}/share/examples/cdk/; \
	done

.include "../../mk/curses.buildlink2.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
