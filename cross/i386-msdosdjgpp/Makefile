# $NetBSD: Makefile,v 1.6 1999/01/04 22:37:33 tv Exp $
#

DISTVERSION=		2.02.0
DISTFILES=		${DJGPP_FILES}
EXTRACT_ONLY=		# none of the djgpp files
MASTER_SITES=		ftp://ftp.simtel.net/pub/simtelnet/gnu/djgpp/v2/ \
			ftp://ftp.simtel.net/pub/simtelnet/gnu/djgpp/v2misc/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.delorie.com/djgpp/

BUILD_DEPENDS=		unzip:../../archivers/unzip

WRKSRC=			${WRKDIR}/djgpp

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	coff-go32
BINUTILS_LDEMULATION=	i386go32
USE_CROSS_EGCS=		yes

DJGPP_FILES=		djcrx202.zip wmemu2b.zip

TARGET_ARCH=		i386-msdosdjgpp
SYS_INCLUDE=		${WRKSRC}/include
SYS_LIB=		${WRKSRC}/lib

post-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC}; \
		for file in ${DJGPP_FILES}; do \
			unzip -Loq ${_DISTDIR}/$$file; \
		done; \
		for file in `find include -type f`; do \
			${CAT} $$file | col >$$file.new; \
			${MV} -f $$file.new $$file; \
		done
	@${LN} -f ${SYS_LIB}/crt0.o ${EGCS_WRKSRC}/gcc/
	@${RM} -f ${SYS_LIB}/djgpp.djl ${SYS_LIB}/specs

post-patch:
	@${RM} -f ${SYS_INCLUDE}/sys/*.orig

do-build:
	cd ${WRKSRC}/src/stub && ${LINK.c} -o stubedit stubedit.c
	cd ${WRKSRC}/src/stub && ${LINK.c} -o stubify stubify.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/stub/stubedit ${TARGET_DIR}/bin/
	${LN} -f ${TARGET_DIR}/bin/stubedit ${PREFIX}/bin/${TARGET_ARCH}-stubedit
	${INSTALL_PROGRAM} ${WRKSRC}/src/stub/stubify ${TARGET_DIR}/bin/
	${LN} -f ${TARGET_DIR}/bin/stubedit ${PREFIX}/bin/${TARGET_ARCH}-stubify
	${INSTALL_DATA} ${WRKSRC}/bin/wmemu387.dxe ${TARGET_DIR}/lib/

.include "../COMMON/cross.mk"
