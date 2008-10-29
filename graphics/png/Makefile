# $NetBSD: Makefile,v 1.107.4.1 2008/10/29 10:05:00 rtr Exp $

DISTNAME=	libpng-1.2.33rc02
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		ftp://ftp.fu-berlin.de/unix/graphics/png/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.libpng.org/pub/png/libpng.html
COMMENT=	Library for manipulating PNG images

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
PKGCONFIG_OVERRIDE=	scripts/libpng.pc.in
TEST_TARGET=	check
USE_LIBTOOL=	yes

.include "../../mk/bsd.prefs.mk"
# keep this in sync with the same code in buildlink3.mk
.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "x86_64"
CPPFLAGS+=	-DPNG_NO_ASSEMBLER_CODE
.endif

SUBST_CLASSES+=		rpathfix
SUBST_FILES.rpathfix=	scripts/libpng-config.in
SUBST_MESSAGE.rpathfix=	Adding rpath to libpng-config.
SUBST_SED.rpathfix=	-e '/^L_opts=/s|-L\([	 ]*[^	 ]*\)"|${COMPILER_RPATH_FLAG}\1 -L\1"|g'
SUBST_STAGE.rpathfix=	pre-configure

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
