# $NetBSD: Makefile,v 1.15 1998/08/17 20:09:51 tron Exp $
# FreeBSD Id: Makefile,v 1.19 1997/12/04 17:34:28 asami Exp
#

DISTNAME=		linux_lib-2.4
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_LOCAL}
ONLY_FOR_ARCHS=		i386

MAINTAINER=		packages@netbsd.org

# The distfile is distributed under the GPL, so no re-distribution of
# binaries without source.
MIRROR_DISTFILE=	no

NO_BUILD=		yes
EXTRACT_ONLY=		# empty
NO_WRKSUBDIR=		yes

EMUL_DIR=	${PREFIX}/emul
LINUX_DIR=	${EMUL_DIR}/linux

pre-install:
	@if [ ! -e /emul ] || \
	    [ "`ls -i /emul/.`" != "`ls -i ${EMUL_DIR}`" ]; \
	 then \
	   ${ECHO} -n "You must create a link \"/emul\" "; \
	   ${ECHO} "pointing to \"${EMUL_DIR}\"."; \
	   exit 1; \
	 fi

do-install:
	${MKDIR} ${LINUX_DIR}/dev
	${LN} -sf /dev/sound ${LINUX_DIR}/dev/dsp
	(cd ${LINUX_DIR}; pax -rzf ${DISTDIR}/${DISTNAME}.tar.gz)
	${MKDIR} ${LINUX_DIR}/usr/local/lib
	${RM} ${LINUX_DIR}/lib/libc.so.5.4.23
	${LN} -sf libc.so.5.3.12 ${LINUX_DIR}/lib/libc.so.5
	${LN} -sf ../../lib/libc.so.5.3.12 ${LINUX_DIR}/usr/lib/libc.so
	-${LINUX_DIR}/sbin/ldconfig
	${MKDIR} ${LINUX_DIR}/usr/lib/zoneinfo
	${LN} -sf /etc/localtime ${LINUX_DIR}/usr/lib/zoneinfo/localtime

.include "../../mk/bsd.pkg.mk"
