# $NetBSD: Makefile,v 1.12 2004/10/03 00:13:29 tv Exp $

DISTNAME=		libast-0.5
PKGREVISION=		7
CATEGORIES=		devel
MASTER_SITES=   	http://www.eterm.org/download/

MAINTAINER=		gendalia@NetBSD.org
HOMEPAGE=		http://freshmeat.net/projects/libast/?topic_id=809%2C861
COMMENT=		The Library of Assorted Spiffy Things

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
TEST_TARGET=		test

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
BUILD_DEFS+=		USE_MMX
. if !empty(USE_MMX:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-mmx
. endif
.endif

.if ${OPSYS} == "SunOS"
LDFLAGS+=-lresolv
.endif

.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
