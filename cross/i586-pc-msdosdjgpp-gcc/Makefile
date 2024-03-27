# $NetBSD: Makefile,v 1.5 2024/03/27 14:38:33 js Exp $

DISTNAME=		gcc-13.2.0
PKGNAME=		cross-i586-pc-msdosdjgpp-${DISTNAME}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-${PKGVERSION_NOREV}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		js@NetBSD.org
HOMEPAGE=		# none
COMMENT=		GCC for DJGPP
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

EXTRACT_USING=		bsdtar

DEPENDS+=		cross-i586-pc-msdosdjgpp-binutils-[0-9]*:../../cross/i586-pc-msdosdjgpp-binutils
DEPENDS+=		cross-i586-pc-msdosdjgpp-sdk-[0-9]*:../../cross/i586-pc-msdosdjgpp-sdk

USE_LANGUAGES+=		c c++

DJGPP_PREFIX=		${PREFIX}/cross-djgpp
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure

CONFIG_SHELL=			${TOOLS_PATH.bash}
WRAPPER_SHELL=			${TOOLS_PATH.bash}
USE_TOOLS+=			bash gmake gsed makeinfo perl
GNU_CONFIGURE=			yes
GNU_CONFIGURE_STRICT=		no # has sub-configures
CHECK_PORTABILITY_SKIP+=	contrib/* gcc/config/nvptx/gen-opt.sh

# Relocations result in a linker error.
MKPIE_SUPPORTED=	no

GNU_CONFIGURE_PREFIX=	${DJGPP_PREFIX}

CONFIGURE_ARGS+=	--target=i586-pc-msdosdjgpp
CONFIGURE_ARGS+=	--enable-languages=c,c++,objc,obj-c++
CONFIGURE_ARGS+=	--disable-nls
# GCC is broken and tries link tests after already setting gcc_no_link=yes if it
# doesn't know the OS. Override them to no to avoid the forbidden link tests.
CONFIGURE_ARGS+=	target_configargs="gcc_cv_have_tls=no ac_cv_func_shl_load=no ac_cv_lib_dld_shl_load=no ac_cv_func_dlopen=no ac_cv_lib_dl_dlopen=no ac_cv_lib_svld_dlopen=no ac_cv_lib_dld_dld_link=no"

INFO_FILES=		yes

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
