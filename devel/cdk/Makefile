# $NetBSD: Makefile,v 1.49 2024/06/26 16:23:34 wiz Exp $

DISTNAME=		cdk-5.0-20240619
PKGNAME=		${DISTNAME:S/5.0-/5.0./}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		https://invisible-island.net/archives/cdk/ \
			https://invisible-mirror.net/archives/cdk/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://invisible-island.net/cdk/
COMMENT=		Curses Development Kit
LICENSE=		x11

WRKSRC=			${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

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
