#	$NetBSD: Makefile,v 1.1 1998/08/12 12:30:59 tv Exp $
#

DISTVERSION=		2.01.1
DISTFILES=		${DJGPP_FILES}
EXTRACT_ONLY=		# none of the djgpp files
MASTER_SITES=		ftp://ftp.simtel.net/pub/simtelnet/gnu/djgpp/v2/ \
			ftp://ftp.simtel.net/pub/simtelnet/gnu/djgpp/v2misc/ \
			ftp://ftp.simtel.net/pub/simtelnet/gnu/djgpp/v2tk/

USE_CROSS_GNU=		yes

BUILD_DEPENDS=		unzip:../../archivers/unzip

DJGPP_FILES=		djcrx201.zip wmemu2b.zip

TARGET_ARCH=		i386-msdosdjgpp
SYS_INCLUDE=		${WRKDIR}/djgpp/include
SYS_LIB=		${WRKDIR}/djgpp/lib

post-extract:
	@${MKDIR} ${WRKDIR}/djgpp
	@cd ${WRKDIR}/djgpp; \
		for file in ${DJGPP_FILES}; do \
			unzip -Loq ${_DISTDIR}/$$file; \
		done; \
		echo 'Stripping CR-LF in includes...'; \
		for file in `find include -type f`; do \
			${CAT} $$file | col >$$file.new; \
			${MV} -f $$file.new $$file; \
		done
	@${LN} -f ${SYS_LIB}/crt0.o ${WRKSRC}/gcc/
	@${RM} -f ${SYS_LIB}/djgpp.djl ${SYS_LIB}/specs

post-patch:
	@${RM} -f ${SYS_INCLUDE}/sys/djtypes.h.orig

post-build:
	cd ${WRKDIR}/djgpp/src/stub && ${LINK.c} -o stubedit stubedit.c
	cd ${WRKDIR}/djgpp/src/stub && ${LINK.c} -o stubify stubify.c

post-install:
	${INSTALL_PROGRAM} ${WRKDIR}/djgpp/src/stub/stubedit ${TARGET_DIR}/bin/
	${LN} -f ${TARGET_DIR}/bin/stubedit ${PREFIX}/bin/${TARGET_ARCH}-stubedit
	${INSTALL_PROGRAM} ${WRKDIR}/djgpp/src/stub/stubify ${TARGET_DIR}/bin/
	${LN} -f ${TARGET_DIR}/bin/stubedit ${PREFIX}/bin/${TARGET_ARCH}-stubify
	${INSTALL_DATA} ${WRKDIR}/djgpp/bin/wmemu387.dxe ${TARGET_DIR}/lib/

.include "../COMMON/cross.mk"
