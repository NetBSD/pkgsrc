# $NetBSD: Makefile,v 1.1 2026/11/14 07:32:58 wiz Exp $

DISTNAME=	stirmake-v0.4.5
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Aalto5G/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	juha-matti.tilli@iki.fi
HOMEPAGE=	https://github.com/Aalto5G/stirmake/
COMMENT=	Fast build tool with better support for recursion than make
LICENSE=	mit

LIBS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC}/stirc && FLEX=false BYACC=false CC=${CC:Q} CFLAGS=${CFLAGS:Q} LDFLAGS=${LDFLAGS:Q} STIR_WITH_LUA=${STIR_WITH_LUA:Q} STIR_LUAINCS=${STIR_LUAINCS:Q} STIR_LUALIBS=${STIR_LUALIBS:Q} STIR_LIBS=${LIBS:Q} ./bootstrapnomake.sh

do-test:
	cd ${WRKSRC}/stirc/autotest && ${SETENV} ${TEST_ENV} FLEX=false BYACC=false ./suite.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stirc/stirmake ${DESTDIR}${PREFIX}/bin/stirmake
	${INSTALL_MAN} ${WRKSRC}/stirc/stirmake.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/stirmake.1
	${LN} -sf stirmake ${DESTDIR}${PREFIX}/bin/smka
	${LN} -sf stirmake ${DESTDIR}${PREFIX}/bin/smkt
	${LN} -sf stirmake ${DESTDIR}${PREFIX}/bin/smkp
	${LN} -sf stirmake.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/smka.1
	${LN} -sf stirmake.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/smkt.1
	${LN} -sf stirmake.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/smkp.1

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
