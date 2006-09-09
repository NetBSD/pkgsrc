# $NetBSD: Makefile,v 1.10 2006/09/09 02:41:58 obache Exp $

DISTNAME=	lcc-4.1
CATEGORIES=	devel lang
MASTER_SITES=	ftp://ftp.cs.princeton.edu/pub/lcc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cs.princeton.edu/software/lcc/
COMMENT=	Local ANSI C compiler for a variety of platforms

MAKE_ENV+=	BUILDDIR=${WRKSRC}/bin HOSTFILE=etc/netbsd.c

# it builds and runs on others (like alpha) but still
# seems to emit i386 assembler
ONLY_FOR_PLATFORM=	*-*-i386

.include "../../mk/bsd.prefs.mk"

BUILDDIR=	${WRKSRC}/src
MAKE_FILE=	makefile

INSTALLATION_DIRS=	bin libexec man/man1

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
