# $NetBSD: Makefile,v 1.11 2018/08/22 09:43:10 wiz Exp $

PKG_VERSION=		3.4.6
# PKGNAME will have option name only when explictly selected
PKGNAME=		nios2-gcc3-${PKG_VERSION}
PKGREVISION=		6
CATEGORIES=		cross
MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU gcc3 for Altera FPGA Nios2 processor
LICENSE=		gnu-gpl-v2

MASTER_SITES=		ftp://ftp.altera.com/outgoing/download/support/ip/processors/nios2/gnu/
DISTNAME=		nios2_gnu_gcc3_10.0
#			nios2_gnu_gcc3_10.1.tgz are the exactly same, see MD5

NOT_FOR_BULK_PLATFORM=	SunOS-*-* NetBSD-*-*

EXTRACT_ELEMENTS=	gcc
WRKSRC=			${WRKDIR}/gcc

USE_TOOLS+=		gmake makeinfo perl
USE_GNU_CONFIGURE_HOST=	no

DEPENDS+=		nios2-binutils-[0-9]*:../../cross/nios2-binutils

GNU_CONFIGURE=		yes

NIOS2_TARGET?=		nios2-elf
PLIST_SUBST+=		NIOS2_TARGET=${NIOS2_TARGET:Q}

GNU_CONFIGURE_PREFIX=	${PREFIX}/cross
PATH:=			${PREFIX}/cross/bin:${PATH}

BUILD_DEPENDS+=		gtexinfo-[0-9]*:../../devel/gtexinfo

.if defined(GNU_CONFIGURE)
CONFIGURE_ARGS=		# reset
CONFIGURE_ARGS+=	--target=${NIOS2_TARGET:Q}
# following line to avoid getting
#    make: exec(nios2--netbsdelf-ar) failed (No such file or directory)
USE_GNU_CONFIGURE_HOST= NO
.endif
CONFIGURE_ARGS+=	--enable-languages=c
CONFIGURE_ARGS+=	--disable-multilib
CONFIGURE_ARGS+=	--disable-threads
CONFIGURE_ARGS+=	--disable-nls
# to avoid strange problem due to long `uname -a` result
CONFIGURE_ARGS+=	--host=${MACHINE_ARCH}--${LOWER_OPSYS}
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}--${LOWER_OPSYS}

# pkglint flags, but seems necessary not generating dir file
INFO_FILES=		no

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
