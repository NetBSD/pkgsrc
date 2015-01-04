# $NetBSD: Makefile,v 1.16 2015/01/04 05:00:45 dholland Exp $

DISTNAME=	lcc-4.1
CATEGORIES=	devel lang
MASTER_SITES=	ftp://ftp.cs.princeton.edu/pub/lcc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sites.google.com/site/lccretargetablecompiler
COMMENT=	Local ANSI C compiler for a variety of platforms

USE_TOOLS+=	yacc
MAKE_ENV+=	BUILDDIR=${WRKSRC}/bin HOSTFILE=etc/netbsd.c

# it builds and runs on others (like alpha) but still
# seems to emit i386 assembler
BROKEN_EXCEPT_ON_PLATFORM=	*-*-i386

.include "../../mk/bsd.prefs.mk"

BUILDDIR=	${WRKSRC}/src
MAKE_FILE=	makefile

INSTALLATION_DIRS=	bin libexec ${PKGMANDIR}/man1

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
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bprint ${DESTDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cpp ${DESTDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lburg ${DESTDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lcc ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rcc ${DESTDIR}${PREFIX}/libexec
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/lcc/include
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/lcc/include/sys
	${INSTALL_DATA} ${WRKSRC}/include/x86/linux/stdarg.h \
		${DESTDIR}${PREFIX}/share/lcc/include
	${INSTALL_DATA} ${FILESDIR}/cdefs.h \
		${DESTDIR}${PREFIX}/share/lcc/include/sys
	${INSTALL_MAN} ${WRKSRC}/doc/lcc.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bprint.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
