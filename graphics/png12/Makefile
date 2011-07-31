# $NetBSD: Makefile,v 1.1.1.1 2011/07/31 17:48:16 jakllsch Exp $

DISTNAME=	libpng-1.2.46
PKGNAME=	png12-1.2.46
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		ftp://ftp.fu-berlin.de/unix/graphics/png/src/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libpng.org/pub/png/libpng.html
COMMENT=	Library for manipulating PNG images

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
PKGCONFIG_OVERRIDE=	scripts/libpng.pc.in
TEST_TARGET=	check
USE_LIBTOOL=	yes

CONFIGURE_ARGS+= --without-libpng-compat

.include "../../mk/bsd.prefs.mk"
# keep this in sync with the same code in buildlink3.mk
.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "x86_64"
CPPFLAGS+=	-DPNG_NO_ASSEMBLER_CODE
.endif

SUBST_CLASSES+=		rpathfix
SUBST_FILES.rpathfix=	scripts/libpng-config.in scripts/libpng.pc-configure.in
SUBST_MESSAGE.rpathfix=	Adding rpath to libpng-config and libpng.pc
SUBST_SED.rpathfix=	-e 's/-L$${libdir}/${COMPILER_RPATH_FLAG}$${libdir} -L$${libdir}/g'
SUBST_STAGE.rpathfix=	pre-configure

post-extract:
	mv ${WRKSRC}/libpng.3 ${WRKSRC}/libpng12.3
	mv ${WRKSRC}/libpngpf.3 ${WRKSRC}/libpngpf12.3
	mv ${WRKSRC}/png.5 ${WRKSRC}/png12.5

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
