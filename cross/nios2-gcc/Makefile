# $NetBSD: Makefile,v 1.14 2018/08/22 09:43:10 wiz Exp $
.include		"../../cross/nios2/Makefile.common"
PKGNAME=		nios2-gcc-${PKG_VERSION}
PKG_VERSION=		4.7.3
PKGREVISION=		6

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU gcc for Altera FPGA Nios2 processor
LICENSE=		gnu-gpl-v3

DEPENDS+=		nios2-binutils>=2.23:../../cross/nios2-binutils

USE_TOOLS+=		ksh gettext gmake makeinfo perl tar automake autoconf gawk
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++
USE_GNU_CONFIGURE_HOST=	no
WRKSRC=			${WRKDIR}/gcc-nios2

# libcpp wants to directly grep in the output
OVERRIDE_DIRDEPTH.depcomp= -1

CONFIGURE_ARGS+=	--enable-languages=c
#CONFIGURE_ARGS+=	--disable-multilib
CONFIGURE_ARGS+=	--disable-threads
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-libssp
# to avoid strange problem due to long `uname -a` result
CONFIGURE_ARGS+=	--host=${MACHINE_ARCH}--${LOWER_OPSYS}
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}--${LOWER_OPSYS}
# See line :2760 of configure
CONFIGURE_ARGS+=	--srcdir=.
CONFIG_SHELL=		ksh
CFLAGS+=		-g

PLIST_VARS+=		doc

SUBST_CLASSES+=			host-subdir
# Work around for the problem
# gmake[2]: *** No rule to make target `../.././gcc/libgcc.mvars'.  Stop.
SUBST_MESSAGE.host-subdir= 	Purely work-around, replacing @host-subdir@ in advance
SUBST_STAGE.host-subdir=	pre-configure
SUBST_FILES.host-subdir=	libgcc/Makefile.in
SUBST_SED.host-subdir=		'-e /host_subdir = @host_subdir@/s,@host_subdir@,host-${MACHINE_ARCH}--${OPSYS:tl},'

.include "options.mk"

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"

do-extract:
	(cd ${WRKDIR}; tar jxf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}	\
	        sourceryg++-2013.05-43-nios2-linux-gnu/gcc-2013.05-43.tar.bz2;\
	tar jxf sourceryg++-2013.05-43-nios2-linux-gnu/gcc-2013.05-43.tar.bz2;\
	)

# to avoid conflict with binutils (to be fixed by more sophisticated way)
post-install:
	${RM}  ${DESTDIR}${PREFIX}/cross/lib/libiberty.a
#  to avoid conflict wit mingw-w64-gcc-4.5.1
	${RM}  ${DESTDIR}${PREFIX}/cross/man/man7/fsf-funding.7
	${RM}  ${DESTDIR}${PREFIX}/cross/man/man7/gfdl.7
	${RM}  ${DESTDIR}${PREFIX}/cross/man/man7/gpl.7
	${RM}  ${DESTDIR}${PREFIX}/cross/info/cpp.info
	${RM}  ${DESTDIR}${PREFIX}/cross/info/cppinternals.info
	${RM}  ${DESTDIR}${PREFIX}/cross/info/gcc.info
	${RM}  ${DESTDIR}${PREFIX}/cross/info/gccinstall.info
	${RM}  ${DESTDIR}${PREFIX}/cross/info/gccint.info

.include "../../mk/bsd.pkg.mk"
