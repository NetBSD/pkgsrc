# $NetBSD: Makefile,v 1.19 2004/10/17 20:12:06 jmmv Exp $
#

DISTNAME=		fam-2.7.0
PKGREVISION=		4
CATEGORIES=		sysutils devel
MASTER_SITES=		ftp://oss.sgi.com/projects/fam/download/stable/	\
			ftp://ftp.tuwien.ac.at/opsys/linux/gentoo/distfiles/ \
			http://gd.tuwien.ac.at/opsys/linux/gentoo/distfiles/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://oss.sgi.com/projects/fam/
COMMENT=		File Alteration Monitor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS} -DNDEBUG"

EGDIR=			${PREFIX}/share/examples/fam
CONF_FILES=		${EGDIR}/fam.conf ${PKG_SYSCONFDIR}/fam.conf

RCD_SCRIPTS=		famd

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	man/famd.conf.5 man/famd.8
SUBST_SED.paths=	-e 's,/usr/local/etc/,${PKG_SYSCONFDIR}/,g'

PKG_OPTIONS_VAR=	PKG_OPTIONS.fam
PKG_SUPPORTED_OPTIONS=	kqueue

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkqueue) && ${OPSYS} == "NetBSD"
CPPFLAGS+=		-DHAVE_KQUEUE

SUBST_CLASSES+=		kqueue
SUBST_MESSAGE.kqueue=	"Enabling kqueue monitoring."
SUBST_STAGE.kqueue=	pre-configure
SUBST_FILES.kqueue=	src/Makefile.in
SUBST_SED.kqueue=	-e 's,@MONITOR_FUNCS@,IMonKQueue,g'
SUBST_SED.kqueue+=	-e 's,@LIBS@,@LIBS@ -lpthread,g'

MESSAGE_SRC=		${.CURDIR}/MESSAGE ${.CURDIR}/MESSAGE.kqueue

.include "../../mk/pthread.buildlink3.mk"
.endif

post-extract:
	${CP} ${FILESDIR}/IMonKQueue.c++ ${WRKSRC}/src
	${CP} ${FILESDIR}/imon-compat.h ${WRKSRC}/src

.include "../../mk/bsd.pkg.mk"
