# $NetBSD: Makefile,v 1.3 2000/09/25 15:59:59 wulf Exp $
# FreeBSD: ports/devel/sdcc/Makefile,v 1.5 2000/04/15 15:13:38 knu Exp

DISTNAME=	sdcc-2.1.9Ea
PKGNAME=	${DISTNAME:S/Ea//}
CATEGORIES=	devel lang
MASTER_SITES=	http://web.kd0yu.com/sdcc/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sdcc.sourceforge.net/

GNU_CONFIGURE=	yes
USE_GMAKE=      yes

ALL_TARGET=	dep all
WRKSRC=         ${WRKDIR}/${DISTNAME:C/[\.-]//g}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=	CPPFLAGS=-I${WRKDIR}/include

post-extract:
	${MKDIR} ${WRKDIR}/include
	${LN} -fs /usr/include/sys/endian.h ${WRKDIR}/include
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sdcc
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/sdcc

.include "../../mk/bsd.pkg.mk"
