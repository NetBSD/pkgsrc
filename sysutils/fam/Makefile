# $NetBSD: Makefile,v 1.41 2016/02/26 10:24:12 jperkin Exp $
#

DISTNAME=		fam-2.7.0
PKGREVISION=		9
CATEGORIES=		sysutils devel
MASTER_SITES=		ftp://oss.sgi.com/projects/fam/download/stable/	\
			${MASTER_SITE_GENTOO:=distfiles/}

CONFLICTS+=		gamin-[0-9]*

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://oss.sgi.com/projects/fam/
COMMENT=		File Alteration Monitor
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2.1 # fam and libfam

# fam is bundled with IRIX
NOT_FOR_PLATFORM=	IRIX-*-*

USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/fam
CONF_FILES=		${EGDIR}/fam.conf ${PKG_SYSCONFDIR}/fam.conf

RCD_SCRIPTS=		famd

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	man/famd.conf.5 man/famd.8
SUBST_SED.paths=	-e 's,/usr/local/etc/,${PKG_SYSCONFDIR}/,g'

PKG_OPTIONS_VAR=	PKG_OPTIONS.fam
PKG_SUPPORTED_OPTIONS=	kqueue

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkqueue) && \
    (${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD")
CPPFLAGS+=		-DHAVE_KQUEUE

SUBST_CLASSES+=		kqueue
SUBST_MESSAGE.kqueue=	Enabling kqueue monitoring.
SUBST_STAGE.kqueue=	pre-configure
SUBST_FILES.kqueue=	src/Makefile.in
SUBST_SED.kqueue=	-e 's,@MONITOR_FUNCS@,IMonKQueue,g'
SUBST_SED.kqueue+=	-e 's,@LIBS@,@LIBS@ -lpthread,g'

MESSAGE_SRC=		${.CURDIR}/MESSAGE ${.CURDIR}/MESSAGE.kqueue

.include "../../mk/pthread.buildlink3.mk"
.endif

CPPFLAGS.Darwin+=	-DNDEBUG
LDFLAGS.SunOS+=		-lsocket -lnsl

SUBST_CLASSES.SunOS+=	sunfix
SUBST_MESSAGE.sunfix=	Fixing ${OPSYS} namespace collision.
SUBST_STAGE.sunfix=	pre-configure
SUBST_FILES.sunfix+=	lib/Client.c++
SUBST_FILES.sunfix+=	src/ClientConnection.c++ src/ClientConnection.h
SUBST_FILES.sunfix+=	src/LocalClient.c++ src/LocalClient.h
SUBST_FILES.sunfix+=	src/Listener.c++
SUBST_FILES.sunfix+=	src/TCP_Client.h
SUBST_SED.sunfix=	-e 's/sun\([^_]\)/sa_un\1/g'

SUBST_CLASSES.SunOS+=	dirent
SUBST_MESSAGE.dirent=	Fixing old sys/dir.h usage.
SUBST_STAGE.dirent=	pre-configure
SUBST_FILES.dirent+=	src/Directory.c++
SUBST_FILES.dirent+=	src/DirectoryScanner.c++ src/DirectoryScanner.h
SUBST_SED.dirent=	-e 's,sys/dir.h,dirent.h,g'
SUBST_SED.dirent+=	-e 's/struct direct/struct dirent/g'

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
BUILDLINK_TRANSFORM+=	rm:-lstdc++
.endif

post-extract:
	${CP} ${FILESDIR}/IMonKQueue.c++ ${WRKSRC}/src
	${CP} ${FILESDIR}/imon-compat.h ${WRKSRC}/src

.include "../../mk/bsd.pkg.mk"
