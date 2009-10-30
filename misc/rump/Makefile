# $NetBSD: Makefile,v 1.7 2009/10/30 13:47:05 stacktic Exp $
#

DISTNAME=		rump_20091030
PKGNAME=		${DISTNAME:S/_/-/}

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

MAKEFLAGS+=		MKMAN=no

MAKEFLAGS+=		TOOLDIR=${WRKSRC}/tooldir
MAKEFLAGS+=		MACHINE_ARCH=${MACHINE_ARCH}
MAKEFLAGS+=		BSDSRCDIR=${WRKSRC}

MAKEFLAGS+=		INSTALL=${WRKSRC}/tools/binstall/xinstall
MAKEFLAGS+=		TSORT="${WRKSRC}/tools/tsort/tsort -q"
MAKEFLAGS+=		LORDER=${WRKSRC}/tools/lorder/lorder

SUBST_CLASSES+=		inc_path
SUBST_STAGE.inc_path=	pre-configure
SUBST_MESSAGE.inc_path=	Adjusting include path.
SUBST_FILES.inc_path=	lib/libukfs/Makefile
SUBST_FILES.inc_path+=	sys/rump/include/rump/Makefile
SUBST_SED.inc_path=	-e "s|/usr/include|${PREFIX}/include|g"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
MAKEFLAGS+=		MACHINE=${MACHINE_ARCH:C/x86_64/amd64/}

CRT_PATH!=		gcc --print-file-name=crtbegin.o
MAKEFLAGS+=		_GCC_CRTBEGIN=${CRT_PATH}
MAKEFLAGS+=		_GCC_CRTBEGINS=${CRT_PATH:C/begin/beginS/}
MAKEFLAGS+=		_GCC_CRTEND=${CRT_PATH:C/begin/end/}
MAKEFLAGS+=		_GCC_CRTENDS=${CRT_PATH:C/begin/endS/}
.endif

RUMP_INCS=		rump.h rump_compat.h rump_namei.h rump_syscalls.h 
RUMP_INCS+=		rumpdefs.h rumpuser.h rumpvnode_if.h

post-install:
.for i in ${RUMP_INCS}
	${INSTALL_DATA} ${WRKSRC}/sys/rump/include/rump/${i} \
		${DESTDIR}${PREFIX}/include/rump
.endfor
	${INSTALL_DATA} ${WRKSRC}/lib/libukfs/ukfs.h \
		${DESTDIR}${PREFIX}/include/rump

.include "../../mk/bsd.pkg.mk"
