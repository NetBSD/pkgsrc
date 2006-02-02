# $NetBSD: Makefile,v 1.22 2006/02/02 19:17:44 rillig Exp $
#

DISTVERSION=		2.0.7.1
PKGREVISION=		1
DISTFILES=		${LINUXDEVEL_FILES}
EXTRACT_ONLY=		# none of the RPM files
MASTER_SITES=		# no known-good site; default to pkgsrc distfile mirrors

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Cross-compile environment for iX86 Linux, libc v6

BUILD_DEPENDS+=		rpm-[0-9]*:../../misc/rpm

CHECK_SHLIBS=		no

WRKSRC=			${WRKDIR}
USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	elf32-i386
BINUTILS_LDEMULATION=	elf_i386
USE_CROSS_EGCS=		yes

LINUXDEVEL_FILES=	glibc-2.0.7-13.i386.rpm \
			glibc-devel-2.0.7-13.i386.rpm \
			kernel-headers-2.0.34-0.6.i386.rpm

TARGET_ARCH=		i386-linux
CROSS_SYS_INCLUDE=	${WRKDIR}/usr/include
SYS_LIB=		${WRKDIR}/usr/lib
LDFLAGS_FOR_TARGET=	-Wl,-rpath-link=${SYS_LIB}

# Extract and rearrange Linux distribution files.
post-extract:
	@cd ${WRKDIR}; \
		for file in ${LINUXDEVEL_FILES}; do \
			${LOCALBASE}/bin/rpm2cpio ${_DISTDIR}/$$file | cpio -id; \
		done
	@cd ${WRKDIR}/lib && ${MV} -f * ${SYS_LIB}
	@cd ${CROSS_SYS_INCLUDE} && ${RM} -f asm linux scsi
	@cd ${WRKDIR}/usr/src/linux-2.0.34/include && \
		${MV} -f asm-i386 ${CROSS_SYS_INCLUDE}/asm && \
		${MV} -f linux scsi ${CROSS_SYS_INCLUDE}
	@cd ${SYS_LIB}; \
		for so in libBrokenLocale libcrypt libdb libdl libm libndbm \
			  libnsl libnss_compat libnss_db libnss_dns \
			  libnss_files libnss_nis libpthread libresolv \
			  libutil; do \
			${LN} -sf $$so.so.* $$so.so; \
		done
	@${LN} -f ${SYS_LIB}/crt* ${EGCS_WRKSRC}/gcc/

post-patch:
	@${RM} -f ${SYS_LIB}/*.orig

post-install:
	@cd ${PREFIX}/${TARGET_ARCH}/lib; \
		${LN} -sf libdb.so libndbm.so; \
		${LN} -sf libbsd-compat.a libbsd.a

.include "../../cross/COMMON/cross.mk"
