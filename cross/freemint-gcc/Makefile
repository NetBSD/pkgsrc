# $NetBSD: Makefile,v 1.3 2014/05/16 13:54:50 ryoon Exp $

DISTNAME=		gcc-4.6.4
PKGNAME=		cross-freemint-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-4.6.4/}

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		http://vincent.riviere.free.fr/soft/m68k-atari-mint/
COMMENT=		GCC compiler for FreeMiNT
EXTRACT_SUFX=		.tar.bz2

PATCH_SITES=	http://vincent.riviere.free.fr/soft/m68k-atari-mint/archives/
PATCHFILES=	gcc-4.6.4-mint-20130415.patch.bz2

WRKSRC=		${WRKDIR}

# for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33549
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
TOOLS_PLATFORM.makeinfo=

DEPENDS+=	cross-freemint-binutils-[0-9]*:../../cross/freemint-binutils
DEPENDS+=	cross-freemint-mintbin-[0-9]*:../../cross/freemint-mintbin

FREEMINT_PREFIX=	${PREFIX}/cross-freemint
CONFIGURE_DIRS=		${DISTNAME}bin
CONFIGURE_SCRIPT=	../${DISTNAME}/configure

USE_TOOLS+=		bash:run gmake makeinfo
GNU_CONFIGURE=		yes

GNU_CONFIGURE_PREFIX=	${FREEMINT_PREFIX}

FIND_PREFIX:=		AR_DIR=cross-freemint-binutils
.include "../../mk/find-prefix.mk"

CFLAGS+=		-fomit-frame-pointer

HOSTDIR=		build-${MACHINE_ARCH}--${LOWER_OPSYS}

CONFIGURE_ARGS+=	--target=m68k-atari-mint
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--disable-libstdcxx-pch
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-multilib

MAKE_ENV+=		SHELL=${TOOLS_PATH.bash}
MAKE_ENV+=		FREEMINT_PREFIX=${FREEMINT_PREFIX}
MAKE_ENV+=		WRKSRC=${WRKSRC}
MAKE_ENV+=		ARDIR=${AR_DIR}/cross-freemint/bin
MAKE_ENV+=		DESTDIR=${DESTDIR}
MAKE_ENV+=		HOSTDIR=${HOSTDIR}
MAKE_ENV+=		CONFIGURE_DIRS=${CONFIGURE_DIRS}
INFO_FILES=		yes

INSTALLATION_DIRS+=	bin

pre-configure:
	mkdir ${WRKSRC}/${CONFIGURE_DIRS}
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/${DISTNAME}
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}/${DISTNAME}

post-install:
	for f in cpp    gcc \
		 c++    g++ \
		 gcov \
		 ; do \
		${LN} -sf ../cross-atari-mint/bin/"m68k-atari-mint-$$f" \
			${DESTDIR}${PREFIX}/bin/"m68k-atari-mint-$$f" || exit 1; \
	done

.include "../../cross/freemint-mintlib/buildlink3.mk"
.include "../../cross/freemint-pml/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
