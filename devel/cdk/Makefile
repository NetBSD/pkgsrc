# $NetBSD: Makefile,v 1.13 2001/05/17 08:38:42 abs Exp $
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

BUILD_DEPENDS+=		autoconf-2.13:../../devel/autoconf

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include	# for ncurses.h
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

ALL_TARGET=		default

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=		ncurses>=4.2:../../devel/ncurses
.elif ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cdk
	for file in ${WRKSRC}/examples/*.c ${WRKSRC}/examples/Makefile; do \
		${INSTALL_DATA} $${file} ${PREFIX}/share/examples/cdk/; \
	done

.include "../../mk/bsd.pkg.mk"
