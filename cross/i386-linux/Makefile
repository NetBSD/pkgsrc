#	$NetBSD: Makefile,v 1.1 1998/08/14 00:10:44 tv Exp $
#

DISTVERSION=		2.0.7.0
DISTFILES=		${LINUXDEVEL_FILES}
EXTRACT_ONLY=		# none of the RPM files
MASTER_SITES=		ftp://ftp.redhat.com/pub/redhat/redhat-5.1/i386/RedHat/RPMS/ \
			ftp://ftp.digital.com/pub/linux/redhat/redhat-5.1/i386/RedHat/RPMS/

USE_CROSS_GNU=		yes

BUILD_DEPENDS=		rpm2cpio:../../misc/rpm

LINUXDEVEL_FILES=	glibc-2.0.7-13.i386.rpm \
			glibc-devel-2.0.7-13.i386.rpm \
			kernel-headers-2.0.34-0.6.i386.rpm

TARGET_ARCH=		i386-linux
SYS_INCLUDE=		${WRKDIR}/usr/include
SYS_LIB=		${WRKDIR}/usr/lib
LDFLAGS_FOR_TARGET=	-Wl,-rpath-link=${SYS_LIB}

# Extract and rearrange Linux distribution files.
post-extract:
	@cd ${WRKDIR}; \
		for file in ${LINUXDEVEL_FILES}; do \
			rpm2cpio ${_DISTDIR}/$$file | cpio -id; \
		done
	@cd ${WRKDIR}/lib && ${MV} -f * ${SYS_LIB}
	@cd ${SYS_INCLUDE} && ${RM} -f asm linux scsi
	@cd ${WRKDIR}/usr/src/linux-2.0.34/include && \
		${MV} -f asm-i386 ${SYS_INCLUDE}/asm && \
		${MV} -f linux scsi ${SYS_INCLUDE}
	@cd ${SYS_LIB}; \
		for so in libBrokenLocale libcrypt libdb libdl libm libndbm \
			  libnsl libnss_compat libnss_db libnss_dns \
			  libnss_files libnss_nis libpthread libresolv \
			  libutil; do \
			${LN} -sf $$so.so.* $$so.so; \
		done
	@${LN} -f ${SYS_LIB}/crt* ${WRKSRC}/gcc/

post-patch:
	@${RM} -f ${SYS_LIB}/*.orig

.include "../COMMON/cross.mk"
