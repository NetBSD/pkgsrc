# $NetBSD: Makefile,v 1.36 2003/09/28 10:41:21 kristerw Exp $
#

DISTNAME=		vice-1.13
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.funet.fi/pub/cbm/firmware/computers/c64/ \
			ftp://ftp.funet.fi/pub/cbm/crossplatform/emulators/VICE/ \
			http://www.nic.funet.fi/pub/cbm/crossplatform/emulators/VICE/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			64gs.390852-01.bin \
			kernal.4064.901246-01.bin \
			kernal.sx.251104-04.bin

MAINTAINER=		kristerw@NetBSD.org
HOMEPAGE=		http://viceteam.bei.t-online.de/
COMMENT=		Emulator for C64, C128, CBM-II, PET, and VIC20

BUILD_USES_MSGFMT=	YES

RESTRICTED=		"ROM image copyright is questionable"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

INFO_FILES=		vice.info

# These changes are rather common, so sed instead of patch:
post-patch:
	@for file in `${FIND} ${WRKSRC} -name Makefile.in -print`	\
			${WRKSRC}/src/arch/unix/archdep.h; do		\
		${MV} -f $$file $$file.orig &&				\
		${SED}  -e "s|/lib/vice/doc|/share/doc/vice|g"		\
			-e "s|/lib/vice|/share/vice|g"			\
			-e "/^pkglibdir/s|(libdir)|(datadir)|g"		\
			$$file.orig >$$file;				\
	done

post-build:
	dd if=${_DISTDIR}/64gs.390852-01.bin of=${WRKDIR}/basic.64gs	\
		bs=8k count=1 2>/dev/null
	dd if=${_DISTDIR}/64gs.390852-01.bin of=${WRKDIR}/kernal.64gs	\
		bs=8k skip=1 2>/dev/null
	${SED}	-e "s|kernal|kernal.64gs|g" -e "s|basic|basic.64gs|g"	\
		${WRKSRC}/data/C64/default.vrs > ${WRKDIR}/64gs.vrs
	${SED}	-e "s|kernal|kernal.4064|g"				\
		${WRKSRC}/data/C64/default.vrs > ${WRKDIR}/4064.vrs
	${SED}	-e "s|kernal|kernal.sx64|g"				\
		${WRKSRC}/data/C64/default.vrs > ${WRKDIR}/sx64.vrs

post-install:
	${INSTALL_DATA} ${WRKDIR}/basic.64gs ${PREFIX}/share/vice/C64/
	${INSTALL_DATA} ${WRKDIR}/kernal.64gs ${PREFIX}/share/vice/C64/
	${INSTALL_DATA} ${_DISTDIR}/kernal.4064.901246-01.bin		\
		${PREFIX}/share/vice/C64/kernal.4064
	${INSTALL_DATA} ${_DISTDIR}/kernal.sx.251104-04.bin		\
		${PREFIX}/share/vice/C64/kernal.sx64
	cd ${WRKDIR} && ${INSTALL_DATA} 64gs.vrs 4064.vrs sx64.vrs	\
		${PREFIX}/share/vice/C64/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/vice
	${MV} ${PREFIX}/share/doc/vice/*.html ${PREFIX}/share/doc/html/vice

.include "../../audio/esound/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
