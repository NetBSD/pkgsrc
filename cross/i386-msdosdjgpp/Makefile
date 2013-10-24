# $NetBSD: Makefile,v 1.32 2013/10/24 10:31:02 wiz Exp $
#

DISTVERSION=		2.02.0
PKGREVISION=		2
DISTFILES=		${DJGPP_FILES}
EXTRACT_ONLY=		# none of the djgpp files
MASTER_SITES=		ftp://ftp.delorie.com/pub/djgpp/deleted/v2/ \
			http://ftp.delorie.com/pub/djgpp/deleted/v2/ \
			ftp://ftp.iij.ad.jp/pub/djgpp/deleted/v2/ \
			ftp://gd.tuwien.ac.at/pc/dos/djgpp/deleted/v2/ \
			http://gd.tuwien.ac.at/pc/dos/djgpp/deleted/v2/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.delorie.com/djgpp/
COMMENT=		Cross-compile environment for MS-DOS on 386 and higher

NOT_FOR_PLATFORM=	*-*-x86_64

SITES.wmemu2b.zip=	http://ftp.delorie.com/pub/djgpp/beta/ \
			ftp://ftp.delorie.com/pub/djgpp/beta/ \
			ftp://ftp.iij.ad.jp/pub/djgpp/beta/ \
			ftp://gd.tuwien.ac.at/pc/dos/djgpp/beta/ \
			http://gd.tuwien.ac.at/pc/dos/djgpp/beta/

PKG_DESTDIR_SUPPORT=	none
BROKEN=			Does not support DESTDIR; will be removed after 2013Q4

WRKSRC=			${WRKDIR}/djgpp
USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	coff-go32
BINUTILS_LDEMULATION=	i386go32
USE_CROSS_EGCS=		yes
USE_TOOLS+=		makeinfo unzip

# Scripts in the build need to have a $CPP defined that works with the built
# compiler
NO_EXPORT_CPP=		yes

DJGPP_FILES=		djcrx202.zip wmemu2b.zip

TARGET_ARCH=		i386-msdosdjgpp
CROSS_SYS_INCLUDE=	${WRKSRC}/include
SYS_LIB=		${WRKSRC}/lib

post-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC}; \
		for file in ${DJGPP_FILES}; do \
			${UNZIP_CMD} -Loq ${_DISTDIR}/$$file; \
		done; \
		for file in `${FIND} include -type f -print`; do \
			${CAT} $$file | col >$$file.new; \
			${MV} -f $$file.new $$file; \
		done
	@${LN} -f ${SYS_LIB}/crt0.o ${EGCS_WRKSRC}/gcc/
	@${RM} -f ${SYS_LIB}/djgpp.djl ${SYS_LIB}/specs

post-patch:
	@${RM} -f ${CROSS_SYS_INCLUDE}/sys/*.orig

do-build:
	cd ${WRKSRC}/src/stub && ${LINK.c} -o stubedit stubedit.c
	cd ${WRKSRC}/src/stub && ${LINK.c} -o stubify stubify.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/stub/stubedit ${TARGET_DIR}/bin/
	${LN} -f ${TARGET_DIR}/bin/stubedit ${PREFIX}/bin/${TARGET_ARCH}-stubedit
	${INSTALL_PROGRAM} ${WRKSRC}/src/stub/stubify ${TARGET_DIR}/bin/
	${LN} -f ${TARGET_DIR}/bin/stubedit ${PREFIX}/bin/${TARGET_ARCH}-stubify
	${INSTALL_DATA} ${WRKSRC}/bin/wmemu387.dxe ${TARGET_DIR}/lib/

.include "../../cross/COMMON/cross.mk"
