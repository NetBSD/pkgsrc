# $NetBSD: Makefile,v 1.1.1.1 2009/10/14 13:26:09 stacktic Exp $
#

DISTNAME=		rump_20091014
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/stacktic/

MAINTAINER=		stacktic@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/docs/rump/
COMMENT=		NetBSD Filesystems in Userspace Libraries

ONLY_FOR_PLATFORM=	Linux-*-* FreeBSD-*-*

INSTALLATION_DIRS=	lib include/rump

CHECK_PORTABILITY=	no
PKG_DESTDIR_SUPPORT=	user-destdir
USE_BSD_MAKEFILE=	yes

WRKSRC=			${WRKDIR}/rump
MAKEFLAGS+=		-m ${WRKSRC}/share/mk
MAKEFLAGS+=		MACHINE_ARCH=${MACHINE_ARCH}
MAKEFLAGS+=		MACHINE_CPU=${MACHINE_ARCH}
MAKEFLAGS+=		MACHINE=${MACHINE_ARCH}
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
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
SUBST_CLASSES+=		linux
SUBST_STAGE.linux=	pre-configure
SUBST_MESSAGE.linux=	Adjusting tsort option.
SUBST_FILES.linux=	share/mk/sys.mk
SUBST_SED.linux=	-e "s|tsort -q|tsort|g"
SUBST_SED.linux+=	-e "s|lorder|${WRKSRC}/bin/lorder|g"
.endif

.if ${OPSYS} != "NetBSD"
SUBST_CLASSES+=		install
SUBST_STAGE.install=	pre-configure
SUBST_MESSAGE.install=	Using NetBSD install
SUBST_FILES.install=	share/mk/sys.mk
SUBST_SED.install=	-e "s|^INSTALL?=.*|INSTALL=${WRKSRC}/tools/binstall/xinstall|g"
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
