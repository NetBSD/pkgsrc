# $NetBSD: Makefile,v 1.4 2009/10/19 16:31:38 stacktic Exp $
#

DISTNAME=		rump_20091014
PKGNAME=		${DISTNAME:S/_/-/}
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/stacktic/

MAINTAINER=		stacktic@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/docs/rump/
COMMENT=		Virtualized NetBSD kernel components in userspace

ONLY_FOR_PLATFORM=	Linux-*-* FreeBSD-*-*

INSTALLATION_DIRS=	lib include/rump

CHECK_PORTABILITY=	no
PKG_DESTDIR_SUPPORT=	user-destdir
USE_BSD_MAKEFILE=	yes

WRKSRC=			${WRKDIR}/rump
MAKEFLAGS+=		-m ${WRKSRC}/share/mk
MAKEFLAGS+=		MKMAN=no

SUBST_CLASSES+=		inc_path
SUBST_STAGE.inc_path=	pre-configure
SUBST_MESSAGE.inc_path=	Adjusting include path.
SUBST_FILES.inc_path=	lib/libukfs/Makefile
SUBST_FILES.inc_path+=	sys/rump/include/rump/Makefile
SUBST_SED.inc_path=	-e "s|/usr/include|${PREFIX}/include|g"

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Adjusting path.
SUBST_FILES.path=	share/mk/bsd.own.mk
SUBST_SED.path=		-e "s|/usr/src|${WRKSRC}|g"
SUBST_SED.path+=	-e "s|NM.*lorder|${WRKSRC}/bin/lorder|g"
SUBST_SED.path+=	-e "s|^INSTALL=.*|INSTALL= ${WRKSRC}/tools/binstall/xinstall|g"

SUBST_CLASSES+=		install
SUBST_STAGE.install=	pre-configure
SUBST_MESSAGE.install=	Using NetBSD install
SUBST_FILES.install=	share/mk/sys.mk
SUBST_SED.install=	-e "s|^INSTALL?=.*|INSTALL=${WRKSRC}/tools/binstall/xinstall|g"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
SUBST_CLASSES+=		linux
SUBST_STAGE.linux=	pre-configure
SUBST_MESSAGE.linux=	Adjusting tsort option.
SUBST_FILES.linux=	share/mk/sys.mk
SUBST_SED.linux=	-e "s|tsort -q|tsort|g"
SUBST_SED.linux+=	-e "s|lorder|${WRKSRC}/bin/lorder|g"

SUBST_CLASSES+=		strlc
SUBST_STAGE.strlc=	pre-configure
SUBST_MESSAGE.strlc=	Fixing strlcat/strlcpy definition.
SUBST_FILES.strlc=	lib/libukfs/Makefile
SUBST_SED.strlc=	-e "s|\#LIB.*|LDADD+= -L${WRKSRC}/tools/compat -lnbcompat|g"

MAKEFLAGS+=		MACHINE=${MACHINE_ARCH:C/x86_64/amd64/}
MAKEFLAGS+=		MACHINE_ARCH=${MACHINE_ARCH}
CRT_PATH!=		gcc --print-file-name=crtbegin.o
MAKEFLAGS+=		_GCC_CRTBEGIN=${CRT_PATH}
MAKEFLAGS+=		_GCC_CRTBEGINS=${CRT_PATH:C/begin/beginS/}
MAKEFLAGS+=		_GCC_CRTEND=${CRT_PATH:C/begin/end/}
MAKEFLAGS+=		_GCC_CRTENDS=${CRT_PATH:C/begin/endS/}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/sys/rump/include/rump/rump.h \
		${DESTDIR}${PREFIX}/include/rump
	${INSTALL_DATA} ${WRKSRC}/sys/rump/include/rump/rump_compat.h \
		${DESTDIR}${PREFIX}/include/rump
	${INSTALL_DATA} ${WRKSRC}/sys/rump/include/rump/rump_namei.h \
		${DESTDIR}${PREFIX}/include/rump
	${INSTALL_DATA} ${WRKSRC}/sys/rump/include/rump/rump_syscalls.h \
		${DESTDIR}${PREFIX}/include/rump
	${INSTALL_DATA} ${WRKSRC}/sys/rump/include/rump/rumpdefs.h \
		${DESTDIR}${PREFIX}/include/rump
	${INSTALL_DATA} ${WRKSRC}/sys/rump/include/rump/rumpuser.h \
		${DESTDIR}${PREFIX}/include/rump
	${INSTALL_DATA} ${WRKSRC}/sys/rump/include/rump/rumpvnode_if.h \
		${DESTDIR}${PREFIX}/include/rump
	${INSTALL_DATA} ${WRKSRC}/lib/libukfs/ukfs.h \
		${DESTDIR}${PREFIX}/include/rump

.include "../../mk/bsd.pkg.mk"
