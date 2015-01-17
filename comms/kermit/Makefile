# $NetBSD: Makefile,v 1.87 2015/01/17 15:30:03 bsiegert Exp $

DISTNAME=	cku302
PKGNAME=	kermit-9.0.302
PKGREVISION=	7
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.kermitproject.org/kermit/archives/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kermitproject.org/
COMMENT=	Network and serial communication, file transfer, and scripting utility

# UNIX C-Kermit 9.0 has been released with the Revised 3-Clause BSD License.
# http://www.columbia.edu/kermit/licensing.html
LICENSE= modified-bsd

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
BUILD_DEFS+=	KFLAGS LIBS MANINSTALL
MAKE_ENV+=	KFLAGS=${KFLAGS:Q} LIBS=${LIBS:Q}
MAKE_FILE=	makefile

LIBS+=		${BUILDLINK_LDADD.termcap}

#KFLAGS+=	-DNODEBUG -DNOOLDMODEMS
KFLAGS+=	${BUILDLINK_CPPFLAGS}
LIBS+=		${BUILDLINK_LDFLAGS}

.include "options.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/kermit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wermit ${DESTDIR}${PREFIX}/bin/kermit
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/doc/kermit
	${INSTALL_MAN} ${WRKSRC}/ckuker.nr \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/kermit.1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"

.if ${OPSYS} == "Darwin"
.  if !empty(OS_VERSION:M??.*)
BUILD_TARGET_OPSYS=	macosx10.6
.  elif !empty(OS_VERSION:M9.*)
BUILD_TARGET_OPSYS=	macosx10.5
.  elif !empty(OS_VERSION:M8.*)
BUILD_TARGET_OPSYS=	macosx10.4
.  elif empty(OS_VERSION:M7.*)
BUILD_TARGET_OPSYS=	macosx103.9
.  else
BUILD_TARGET_OPSYS=	macosx10
.  endif
.elif ${OPSYS} == "Linux"
BUILD_TARGET_OPSYS=	linux
MAKE_ENV+=	HAVE_LIBCURSES=-l${BUILDLINK_LIBNAME.curses}
.  if ${CURSES_TYPE} == "ncurses"
MAKE_ENV+=	HAVE_CURSES=-DCK_NCURSES
.  else
MAKE_ENV+=	HAVE_CURSES=-DCK_NCURSES
.  endif
.elif ${OPSYS} == "SunOS"
BUILD_TARGET_OPSYS=	solaris11g
.else
BUILD_TARGET_OPSYS=	netbsd
.endif

BUILD_TARGET=	${BUILD_TARGET_OPSYS}${BUILD_TARGET_OPTIONS:ts}

.include "../../mk/bsd.pkg.mk"
