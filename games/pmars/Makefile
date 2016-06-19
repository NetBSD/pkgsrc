# $NetBSD: Makefile,v 1.3 2016/06/19 23:02:06 joerg Exp $
#

DISTNAME=		pmars-0.9.2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=corewar/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.koth.org/pmars/
COMMENT=		The official Core Wars simulator
LICENSE=		gnu-gpl-v2

BUILD_DIRS=		src
BUILD_MAKE_FLAGS+=	CC=${CC:Q}
BUILD_MAKE_FLAGS+=	LIB="${COMPILER_RPATH_FLAG}${X11BASE}/lib -L${X11BASE}/lib -lX11"

INSTALLATION_DIRS+=	bin share/pmars share/pmars/config share/pmars/warriors ${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pmars ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/pmars
	${INSTALL_DATA} ${WRKSRC}/CONTRIB ${DESTDIR}${PREFIX}/share/pmars
	${INSTALL_DATA} ${WRKSRC}/config/* ${DESTDIR}${PREFIX}/share/pmars/config
	${INSTALL_DATA} ${WRKSRC}/warriors/* ${DESTDIR}${PREFIX}/share/pmars/warriors
	${INSTALL_MAN} ${WRKSRC}/doc/pmars.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
