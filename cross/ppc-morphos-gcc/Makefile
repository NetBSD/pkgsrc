# $NetBSD: Makefile,v 1.2 2026/04/04 01:29:41 js Exp $

DISTNAME=	gcc-15.1.0
PKGREVISION=	1
PKGNAME=	ppc-morphos-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://www.morphos-team.net/
COMMENT=	GCC for ppc-morphos
LICENSE=	gnu-gpl-v3

DEPENDS+=		ppc-morphos-binutils-[0-9]*:../../cross/ppc-morphos-binutils
DEPENDS+=		ppc-morphos-sdk-[0-9]*:../../cross/ppc-morphos-sdk

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		xzcat gtar patch autoconf gsed gmake perl makeinfo

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

pre-patch:
	# Out of memory with gpatch on Darwin, so use nbpatch.
	${RUN} cd ${WRKSRC} && ${PATCH} -p1 <${FILESDIR}/gcc-15-morphos.diff
	${RUN} cd ${WRKSRC} && ${PATCH} -p0 <${FILESDIR}/fpic.diff
	${RUN} cd ${WRKSRC} && ${PATCH} -p1 <${FILESDIR}/fix-fenv-for-crossbuild.diff
	${RUN} cd ${WRKSRC} && ${PATCH} -p1 <${FILESDIR}/morphos-std-filesystem-path.diff
	${RUN} cd ${WRKSRC} && ${PATCH} -p1 <${FILESDIR}/morphos-std-fastfloat.diff
	${RUN} cd ${WRKSRC} && ${PATCH} -p0 <${FILESDIR}/fix-saveds.diff
	${RUN} cd ${WRKSRC} && ${PATCH} -p0 <${FILESDIR}/objc-saveds.diff
	${RUN} find ${WRKSRC} -name configure -print0 | xargs -0 -r perl -i.orig -p -e "s|toolexecdir='\\\$$\(libdir\)/gcc/\\\$$\(target_alias\)'|toolexecdir='\\\$$(libdir)/gcc-lib/\\\$$(target_alias)'|g;"
	${RUN} find ${WRKSRC} -name Makefile.in -print0 | xargs -0 -r perl -i.orig -p -e "s|= \\\$$\(libexecdir\)/gcc/\\\$$\(real_target_noncanonical\)|= \\\$$(libexecdir)/gcc-lib/\\\$$(real_target_noncanonical)|g;s|= \\\$$\(libdir\)/gcc/\\\$$\(target_noncanonical\)|= \\\$$(libdir)/gcc-lib/\\\$$(target_noncanonical)|g;"

post-patch:
	# Change /gg to ${PREFIX}/gg
	${RUN} cd ${WRKSRC} && \
		gsed -i 's,/gg/,${PREFIX}/gg/,g' \
			gcc/config/rs6000/morphos.h && \
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
