# $NetBSD: Makefile,v 1.8 2014/05/05 20:14:55 adam Exp $

DISTNAME=	util-linux-2.24.2
PKGNAME=	${DISTNAME:S/util-linux/libuuid/}
CATEGORIES=	devel
MASTER_SITES=	http://www.kernel.org/pub/linux/utils/util-linux/v${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kernel.org/~kzak/util-linux-ng/
COMMENT=	Generate unique identifiers for objects
LICENSE=	modified-bsd

USE_GCC_RUNTIME=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-ncurses

PKGCONFIG_OVERRIDE+=	libuuid/uuid.pc.in

BUILD_TARGET=		libuuid.la libuuid/uuid.pc
INSTALLATION_DIRS+=	include/uuid lib/pkgconfig ${PKGMANDIR}/man3

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-Wl,--version-script=./libuuid/src/uuid.sym
.endif

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libuuid.la \
		${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libuuid/src/uuid.h \
		${DESTDIR}${PREFIX}/include/uuid/uuid.h
	${INSTALL_DATA} ${WRKSRC}/libuuid/uuid.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig/uuid.pc
	set -e; for f in ${WRKSRC}/libuuid/man/*.3; do \
		${INSTALL_MAN} $${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/; \
	done

.include "../../mk/bsd.pkg.mk"
