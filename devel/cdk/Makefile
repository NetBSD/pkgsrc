# $NetBSD: Makefile,v 1.40 2019/06/22 11:37:13 nia Exp $

DISTNAME=		cdk-5.0-20180306
PKGNAME=		${DISTNAME:S/5.0-/5.0./}
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.invisible-island.net/cdk/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://invisible-island.net/cdk/
COMMENT=		Curses Development Kit

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_NCURSES=		yes # uses ncurses internals
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

BUILD_TARGET=		default

INSTALL_MAKE_FLAGS+=	INSTALL_DIR=${DESTDIR}${PREFIX} \
			MAN_DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
INSTALLATION_DIRS=	share/examples/cdk

# put Cdk's include-directory at the front to avoid conflict with menu.h
CFLAGS+=		-I./include

post-install:
	for file in ${WRKSRC}/examples/*.c ${WRKSRC}/examples/Makefile; do \
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/share/examples/cdk/; \
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
