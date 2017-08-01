# $NetBSD: Makefile,v 1.38 2017/08/01 17:40:09 wiz Exp $
#

DISTNAME=		latestCDK
PKGNAME=		cdk-4.9.9
PKGREVISION=		5
CATEGORIES=		devel
MASTER_SITES=		http://www.vexus.ca/release/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.vexus.ca/products/CDK/
COMMENT=		Curses Development Kit

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_NCURSES=		yes # uses ncurses internals
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf213

BUILD_TARGET=		default

INSTALL_MAKE_FLAGS+=	INSTALL_DIR=${DESTDIR}${PREFIX} \
			MAN_DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
INSTALLATION_DIRS=	share/examples/cdk

pre-configure:
	cd ${WRKSRC}; autoconf

post-install:
	for file in ${WRKSRC}/examples/*.c ${WRKSRC}/examples/Makefile; do \
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/share/examples/cdk/; \
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
