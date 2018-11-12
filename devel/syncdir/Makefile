# $NetBSD: Makefile,v 1.12 2018/11/12 17:54:40 schmonz Exp $
#

DISTNAME=		syncdir-1.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/syncdir/
COMMENT=		Synchronous open, link, rename, and unlink
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

.include "../../mk/bsd.pkg.mk"
