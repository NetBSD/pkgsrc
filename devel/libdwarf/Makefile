# $NetBSD: Makefile,v 1.2 2016/12/11 21:34:26 kamil Exp $

DISTNAME=	libdwarf-20161124
CATEGORIES=	devel
MASTER_SITES=	https://www.prevanders.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.prevanders.net/dwarf.html
COMMENT=	Tools for parsing DWARF debug information
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

WRKSRC=		${WRKDIR}/dwarf-${PKGVERSION_NOREV}
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--enable-shared

MAKE_JOBS_SAFE=	no

INSTALLATION_DIRS+=	bin lib include ${PKGMANDIR}/man1 share/doc/libdwarf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dwarfdump/dwarfdump ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dwarfdump/dwarfdump.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_LIB} ${WRKSRC}/libdwarf/libdwarf.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libdwarf/libdwarf.so ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libdwarf/libdwarf.so.1 ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libdwarf/dwarf.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libdwarf/libdwarf.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libdwarf/*.pdf ${DESTDIR}${PREFIX}/share/doc/libdwarf

.include "../../devel/libelf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
