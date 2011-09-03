# $NetBSD: Makefile,v 1.15 2011/09/03 20:35:48 alnsn Exp $
#

DISTNAME=		rump_20091108
PKGNAME=		${DISTNAME:S/_/-/}
PKGREVISION=		3

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
MAKEFLAGS+=		NOGCCERROR=1

SUBST_CLASSES+=		alloc
SUBST_STAGE.alloc=	pre-configure
SUBST_MESSAGE.alloc=	Using malloc.
SUBST_FILES.alloc=	sys/rump/librump/rumpkern/Makefile.rumpkern
SUBST_SED.alloc=	-e "s|CPPFLAGS.*USE_REAL_ALLOCATORS.*|\# &|"
SUBST_SED.alloc+=	-e "s|SRCS.*subr_pool.*|\# &|"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"

SUBST_CLASSES+=		crt
SUBST_STAGE.crt=	pre-configure
SUBST_MESSAGE.crt=	Fix crt path.
SUBST_FILES.crt=	share/mk/bsd.lib.mk share/mk/bsd.prog.mk
SUBST_SED.crt=		-e "s|lib/crt|lib$$\{LIBABISUFFIX\}/crt|"
MAKEFLAGS+=		LIBABISUFFIX=${LIBABISUFFIX}

SUBST_CLASSES+=		dl
SUBST_STAGE.dl=		pre-configure
SUBST_MESSAGE.dl=	Fix dlopen.
SUBST_FILES.dl=		lib/libukfs/ukfs.c
SUBST_SED.dl=		-e "s|RTLD_GLOBAL|&\|RTLD_LAZY|"

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

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
