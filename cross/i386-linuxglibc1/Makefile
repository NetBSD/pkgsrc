# $NetBSD: Makefile,v 1.2 1998/08/23 20:43:41 frueauf Exp $
#

DISTVERSION=		5.3.12.0
DISTFILES=		${LINUXDEVEL_FILES}
EXTRACT_ONLY=		# none of the RPM files
MASTER_SITES=		ftp://ftp.redhat.com/pub/redhat/redhat-4.2/i386/RedHat/RPMS/ \
			ftp://ftp.digital.com/pub/linux/redhat/redhat-4.2/i386/RedHat/RPMS/

MAINTAINER=		packages@netbsd.org

BUILD_DEPENDS=		rpm2cpio:../../misc/rpm

USE_CROSS_GNU=		yes

LINUXDEVEL_FILES=	libc-5.3.12-18.i386.rpm \
			libc-devel-5.3.12-18.i386.rpm \
			libc-static-5.3.12-18.i386.rpm \
			kernel-headers-2.0.30-2.i386.rpm

TARGET_ARCH=		i386-linuxglibc1
SYS_INCLUDE=		${WRKDIR}/usr/include
SYS_LIB=		${WRKDIR}/usr/lib

# Extract and rearrange Linux distribution files.
post-extract:
	@cd ${WRKDIR}; \
		for file in ${LINUXDEVEL_FILES}; do \
			rpm2cpio ${_DISTDIR}/$$file | cpio -id; \
		done
	@cd ${WRKDIR}/lib && ${MV} -f * ../usr/lib/
	@cd ${WRKDIR}/usr/lib && \
		${LN} -sf libc.so.*.* libc.so && \
		${LN} -sf libm.so.*.* libm.so
	@cd ${WRKDIR}/usr/include && ${RM} -f asm linux scsi
	@cd ${WRKDIR}/usr/src/linux-2.0.30/include && \
		${MV} -f asm-i386 ${WRKDIR}/usr/include/asm && \
		${MV} -f linux scsi ${WRKDIR}/usr/include/
	@${LN} -f ${WRKDIR}/usr/lib/crt*.o ${WRKSRC}/gcc/

.include "../COMMON/cross.mk"
