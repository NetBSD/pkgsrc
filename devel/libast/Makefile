# $NetBSD: Makefile,v 1.3 2003/05/02 11:54:34 wiz Exp $

DISTNAME=		libast-0.5
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=   	http://www.eterm.org/download/

MAINTAINER=		gendalia@netbsd.org
HOMEPAGE=		http://freshmeat.net/projects/libast/?topic_id=809%2C861
COMMENT=		The Library of Assorted Spiffy Things

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
TEST_TARGET=		test

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" && ${USE_MMX} != "NO"
CONFIGURE_ARGS+=	--enable-mmx
.endif
BUILD_DEFS+=		USE_MMX

.if ${OPSYS} == "SunOS"
LDFLAGS+=-lresolv
.endif

.include "../../devel/pcre/buildlink2.mk"
.include "../../graphics/imlib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
