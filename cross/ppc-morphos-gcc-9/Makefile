# $NetBSD: Makefile,v 1.4 2020/06/02 18:37:46 rillig Exp $

DISTNAME=	sdk-source-20191111
PKGNAME=	ppc-morphos-gcc-9-9.2.0
PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	https://morphos-team.net/files/src/sdk/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://www.morphos-team.net/
COMMENT=	GCC 9 for ppc-morphos
LICENSE=	gnu-gpl-v3

DEPENDS+=		ppc-morphos-binutils-[0-9]*:../../cross/ppc-morphos-binutils
DEPENDS+=		ppc-morphos-sdk-[0-9]*:../../cross/ppc-morphos-sdk

WRKSRC=			${WRKDIR}/sdk-source/gcc9/gcc-${PKGVERSION_NOREV}
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
CONFIGURE_ARGS+=	--program-suffix=-9
CONFIGURE_ARGS+=	--enable-threads=morphos
CONFIGURE_ARGS+=	--disable-bootstrap
CONFIGURE_ARGS+=	--enable-version-specific-runtime-libs

CHECK_PORTABILITY_SKIP+=	contrib/*
CHECK_PORTABILITY_SKIP+=	libgo/mksysinfo.sh

post-extract:
	${RUN} cd ${WRKDIR}/sdk-source/gcc9 && \
		${XZCAT} gcc-${PKGVERSION_NOREV}.tar.xz | ${GTAR} xf -

pre-patch:
	${RUN} cd ${WRKSRC} && ${PATCH} -p1 <../gcc-9-morphos.diff
	# The diff for libstdc++-v3/configure is strangely large for the
	# minimal changes that are there to the .ac file. Better to throw it
	# away and regenerate it.
	${RUN} rm ${WRKSRC}/libstdc++-v3/configure
	${RUN} cd ${WRKSRC}/libstdc++-v3 && autoconf
	# Change /gg to ${PREFIX}/gg
	${RUN} cd ${WRKSRC} && \
		gsed -i 's,/gg/,${PREFIX}/gg/,g' gcc/config/rs6000/morphos.h && \
		gsed -i 's,/gg$$,${PREFIX}/gg,g' gcc/config.host

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

post-install:
	${RUN} rm -f ${DESTDIR}${PREFIX}/gg/share/info/dir

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
