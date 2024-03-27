# $NetBSD: Makefile,v 1.6 2024/03/27 23:26:29 js Exp $

DISTNAME=	sdk-source-20230510
PKGNAME=	ppc-morphos-gcc-11-11.3.0
CATEGORIES=	cross
MASTER_SITES=	https://morphos-team.net/files/src/sdk/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://www.morphos-team.net/
COMMENT=	GCC 11 for ppc-morphos
LICENSE=	gnu-gpl-v3

DEPENDS+=		ppc-morphos-binutils-[0-9]*:../../cross/ppc-morphos-binutils
DEPENDS+=		ppc-morphos-sdk-[0-9]*:../../cross/ppc-morphos-sdk

WRKSRC=			${WRKDIR}/sdk-source/gcc11/gcc-${PKGVERSION_NOREV}
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		xzcat gtar patch autoconf gsed gmake perl makeinfo
TOOL_DEPENDS+=		patch-[0-9]*:../../devel/patch

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${PREFIX}/gg
CONFIGURE_ARGS+=	--target=ppc-morphos
CONFIGURE_ARGS+=	--with-plugin-ld=no
CONFIGURE_ARGS+=	--enable-languages=c,c++,objc,obj-c++
CONFIGURE_ARGS+=	--with-sysroot=${PREFIX}/gg
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/gg/lib
CONFIGURE_ARGS+=	--oldincludedir=${PREFIX}/gg/include
CONFIGURE_ARGS+=	--program-prefix=ppc-morphos-
CONFIGURE_ARGS+=	--program-suffix=-11
CONFIGURE_ARGS+=	--enable-threads=morphos
CONFIGURE_ARGS+=	--disable-bootstrap
CONFIGURE_ARGS+=	--enable-version-specific-runtime-libs
CONFIGURE_ARGS+=	--disable-nls
# Used by a sub-configure, therefore needs to be passed via MAKE_ENV.
MAKE_ENV+=		gcc_cv_have_tls=no

# Relocations result in a linker error.
MKPIE_SUPPORTED=	no

CHECK_PORTABILITY_SKIP+=	contrib/*
CHECK_PORTABILITY_SKIP+=	libgo/mksysinfo.sh

post-extract:
	${RUN} cd ${WRKDIR}/sdk-source/gcc11 && \
		${XZCAT} gcc-${PKGVERSION_NOREV}.tar.xz | ${GTAR} xf -

pre-patch:
	${RUN} cd ${WRKSRC} && ${PREFIX}/bin/gpatch -p1 <../gcc-11-morphos.diff
	${RUN} cd ${WRKSRC} && ${PREFIX}/bin/gpatch -p0 <../fpic.diff
	${RUN} cd ${WRKSRC} && ${PREFIX}/bin/gpatch -p1 <../fix-genericize_if_stmt-ice.diff
	${RUN} cd ${WRKSRC} && ${PREFIX}/bin/gpatch -p1 <../morphos-std-filesystem-path.diff
	${RUN} cd ${WRKSRC} && ${PREFIX}/bin/gpatch -p1 <../fix-fenv-for-crossbuild.diff
	# The diff for libstdc++-v3/configure is strangely large for the
	# minimal changes that are there to the .ac file *and* is broken (it
	# contains misordered hunks). Better to throw it away and regenerate it
	# (regenerated in post-patch).
	${RUN} rm ${WRKSRC}/libstdc++-v3/configure

post-patch:
	# Change /gg to ${PREFIX}/gg
	${RUN} cd ${WRKSRC} && \
		gsed -i 's,/gg/,${PREFIX}/gg/,g' gcc/config/rs6000/morphos.h && \
		gsed -i 's,/gg$$,${PREFIX}/gg,g' gcc/config.host
	${RUN} cd ${WRKSRC}/libcc1 && autoreconf
	${RUN} cd ${WRKSRC}/libstdc++-v3 && autoreconf
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

post-install:
	${RUN} rm -f ${DESTDIR}${PREFIX}/gg/share/info/dir

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
