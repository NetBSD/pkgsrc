# $NetBSD: Makefile,v 1.1.1.1 2001/07/21 02:51:35 gmcgarry Exp $

DISTNAME=	lcc-4.1
CATEGORIES=	devel lang
MASTER_SITES=	ftp://ftp.cs.princeton.edu/pub/lcc/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.research.microsoft.com/~cwfraser/

MAKE_ENV+=	BUILDDIR=${WRKSRC}/bin HOSTFILE=etc/netbsd.c

.include "../../mk/bsd.prefs.mk"

BUILDDIR=	${WRKSRC}/src
MAKEFILE=	makefile

post-extract:
	${CP} ${FILESDIR}/x86bsd.md ${WRKSRC}/src/
	${CP} ${FILESDIR}/netbsd.c ${WRKSRC}/etc/

pre-build:
	${MKDIR} ${WRKSRC}/bin
	cd ${WRKSRC}/etc ; \
		[ -f netbsd.c.bak ] || ${MV} netbsd.c netbsd.c.bak ; \
		${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' < netbsd.c.bak > netbsd.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bprint ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cpp ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lburg ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lcc ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rcc ${PREFIX}/libexec
	${INSTALL_DATA_DIR} ${PREFIX}/share/lcc/include
	${INSTALL_DATA_DIR} ${PREFIX}/share/lcc/include/sys
	${INSTALL_DATA} ${WRKSRC}/include/x86/linux/stdarg.h \
		${PREFIX}/share/lcc/include
	${INSTALL_DATA} ${FILESDIR}/cdefs.h \
		${PREFIX}/share/lcc/include/sys
	${INSTALL_MAN} ${WRKSRC}/doc/lcc.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bprint.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
