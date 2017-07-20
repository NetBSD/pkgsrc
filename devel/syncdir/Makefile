# $NetBSD: Makefile,v 1.11 2017/07/20 02:07:27 schmonz Exp $
#

DISTNAME=		syncdir-1.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/syncdir/
COMMENT=		Implementation of open, link, rename, and unlink
LICENSE=		gnu-gpl-v2

USE_LIBTOOL=		yes

INSTALLATION_DIRS=	lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
SUBST_CLASSES+=		fsync
SUBST_STAGE.fsync=	do-configure
SUBST_FILES.fsync=	syncdir.c
SUBST_SED.fsync=	-e 's|syscall(SYS_fsync, FD)|fsync(FD)|'
.endif

do-build:
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile ${CC} ${CFLAGS} -c syncdir.c
	cd ${WRKSRC} && ${LIBTOOL} --mode=link ${CC} ${LDFLAGS}		\
		-o libsyncdir.la syncdir.lo				\
		-version-info 1:0:0 -rpath ${PREFIX}/lib

do-install:
	cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_LIB}	\
		-c libsyncdir.la ${DESTDIR}${PREFIX}/lib/libsyncdir.la

.include "../../mk/bsd.pkg.mk"
