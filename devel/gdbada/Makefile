# $NetBSD: Makefile,v 1.12 2006/03/20 07:26:29 jlam Exp $

DISTNAME=	gdbada-6.3
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.johnrshannon.com/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	john@johnrshannon.com
HOMEPAGE=	http://libre.act-europe.fr/GDB/
COMMENT=        GNAT GDB : An Ada 95 Debugger

# Not yet ported to AMD 64-bit machines or Darwin
NOT_FOR_PLATFORM=	*-*-x86_64 Darwin-*-*

WRKSRC=			${WRKDIR}/gdb-6.3

USE_TOOLS+=		gmake makeinfo
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=          YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/gdbada
# We don't seem to be able to control where locale data goes, so:
CONFIGURE_ARGS+=	--disable-nls
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}

INFO_FILES=		# PLIST
TEST_TARGET=    	check

pre-patch:
	${CP} ${FILESDIR}/nbsd-nat.c ${WRKSRC}/gdb

.include "../../mk/bsd.prefs.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
