# $NetBSD: Makefile,v 1.8 2005/12/05 23:55:05 rillig Exp $

DISTNAME=	gdbada-6.3
#PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=		http://www.johnrshannon.com/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=	john@johnrshannon.com
HOMEPAGE=	http://libre.act-europe.fr/GDB/
COMMENT=        GNAT GDB : An Ada 95 Debugger

# Not yet ported to AMD 64-bit machines or Darwin
NOT_FOR_PLATFORM=	*-*-x86_64 Darwin-*-*

WRKSRC=		${WRKDIR}/gdb-6.3
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GDB_SUBPREFIX=	gdbada
GDB_PREFIX=	${PREFIX}/${GDB_SUBPREFIX}
GNU_CONFIGURE=          YES
USE_PKGINSTALL=		YES
USE_TOOLS+=		gmake
TEST_TARGET=    	check
INFO_DIR=		${GDB_PREFIX}/info
LIB_DIR=		${GDB_PREFIX}/lib
CONFIGURE_ARGS+=	--prefix=${GDB_PREFIX:Q}
CONFIGURE_ARGS+=	--exec-prefix=${GDB_PREFIX:Q}
CONFIGURE_ARGS+=	--infodir=${INFO_DIR:Q}
CONFIGURE_ARGS+=	--libdir=${LIB_DIR:Q}
CONFIGURE_ARGS+=	--includedir=${GDB_PREFIX}/include
CONFIGURE_ARGS+=	--mandir=${GDB_PREFIX}/man
CONFIGURE_ARGS+=	--datadir=${GDB_PREFIX}/share
# We don't seem to be able to control where locale data goes, so:
CONFIGURE_ARGS+=	--disable-nls
USE_MAKEINFO=		YES
USE_NEW_TEXINFO=	YES

pre-patch:
	${CP} ${FILESDIR}/nbsd-nat.c ${WRKSRC}/gdb

.include "../../mk/bsd.prefs.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
