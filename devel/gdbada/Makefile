# $NetBSD: Makefile,v 1.19 2012/08/14 17:07:56 asau Exp $

DISTNAME=	gdbada-6.3
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.johnrshannon.com/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	john@johnrshannon.com
HOMEPAGE=	https://libre.adacore.com/GDB/
COMMENT=	GNAT GDB : An Ada 95 Debugger

# Not yet ported to AMD 64-bit machines or Darwin
NOT_FOR_PLATFORM=	*-*-x86_64 Darwin-*-* DragonFly-*-*

PKG_DESTDIR_SUPPORT=	none

WRKSRC=			${WRKDIR}/gdb-6.3

USE_TOOLS+=		gmake makeinfo
USE_LIBTOOL=		yes

GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/gdbada
# We don't seem to be able to control where locale data goes, so:
CONFIGURE_ARGS+=	--disable-nls
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:M*:Q}

INFO_FILES=		yes
TEST_TARGET=	check

pre-patch:
	${CP} ${FILESDIR}/nbsd-nat.c ${WRKSRC}/gdb

.include "../../mk/bsd.prefs.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
