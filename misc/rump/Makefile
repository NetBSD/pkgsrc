# $NetBSD: Makefile,v 1.11 2009/11/08 20:13:26 stacktic Exp $
#

DISTNAME=		rump_20091108
PKGNAME=		${DISTNAME:S/_/-/}

CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/stacktic/

MAINTAINER=		stacktic@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/docs/rump/
COMMENT=		Virtualized NetBSD kernel components in userspace

ONLY_FOR_PLATFORM=	Linux-*-* FreeBSD-*-*

INSTALLATION_DIRS=	lib include/rump ${PKGMANDIR}/man3

PKG_DESTDIR_SUPPORT=	user-destdir
USE_BSD_MAKEFILE=	yes

WRKSRC=			${WRKDIR}/rump

MAKEFLAGS+=		MACHINE_ARCH=${MACHINE_ARCH}
MAKEFLAGS+=		BSDSRCDIR=${WRKSRC}

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
RUMP_INCS+=		rumpkern_if_pub.h rumpnet_if_pub.h rumpvfs_if_pub.h

post-install:
.for i in ${RUMP_INCS}
	${INSTALL_DATA} ${WRKSRC}/sys/rump/include/rump/${i} \
		${DESTDIR}${PREFIX}/include/rump
.endfor
	${INSTALL_DATA} ${WRKSRC}/lib/libukfs/ukfs.h \
		${DESTDIR}${PREFIX}/include/rump

.include "../../mk/bsd.pkg.mk"
