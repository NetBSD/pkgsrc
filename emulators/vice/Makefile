# $NetBSD: Makefile,v 1.7 1999/11/23 16:26:12 hubertf Exp $

DISTNAME=		vice-1.0
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.funet.fi/pub/cbm/firmware/computers/c64/ \
			ftp://ftp.funet.fi/pub/cbm/crossplatform/emulators/VICE/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			64gs.390852-01.bin \
			kernal.4064.901246-01.bin \
			kernal.sx.251104-04.bin
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.cs.cmu.edu/~dsladic/vice/vice.html

RESTRICTED=		"ROM image copyright is questionable"
NO_CDROM=		${RESTRICTED}
NO_PACKAGE=		${RESTRICTED}
MIRROR_DISTFILE=	no

GNU_CONFIGURE=		yes
USE_X11=		yes
USE_GTEXINFO=		yes

# These changes are rather common, so sed instead of patch:
post-patch:
	@for file in `find ${WRKSRC} -name Makefile.in -print` \
			${WRKSRC}/src/arch/unix/archdep.h; do \
		${MV} -f $$file $$file.orig && \
		${SED}  -e s,/lib/vice/doc,/share/doc/vice, \
			-e s,/lib/vice,/share/vice, \
			-e '/^pkglibdir/s,(libdir),(datadir),' $$file.orig >$$file; \
	done

post-build:
	@dd if=${_DISTDIR}/64gs.390852-01.bin of=${WRKDIR}/basic.64gs bs=8k count=1 2>/dev/null
	@dd if=${_DISTDIR}/64gs.390852-01.bin of=${WRKDIR}/kernal.64gs bs=8k skip=1 2>/dev/null
	@${SED} -e 's,kernal,kernal.64gs,' -e 's,basic,basic.64gs,' \
		${WRKSRC}/data/C64/default.vrs >${WRKDIR}/64gs.vrs
	@${SED} -e 's,kernal,kernal.4064,' \
		${WRKSRC}/data/C64/default.vrs >${WRKDIR}/4064.vrs
	@${SED} -e 's,kernal,kernal.sx64,' \
		${WRKSRC}/data/C64/default.vrs >${WRKDIR}/sx64.vrs

post-install:
	${INSTALL_DATA} ${WRKDIR}/basic.64gs ${PREFIX}/share/vice/C64/
	${INSTALL_DATA} ${WRKDIR}/kernal.64gs ${PREFIX}/share/vice/C64/
	${INSTALL_DATA} ${_DISTDIR}/kernal.4064.901246-01.bin ${PREFIX}/share/vice/C64/kernal.4064
	${INSTALL_DATA} ${_DISTDIR}/kernal.sx.251104-04.bin ${PREFIX}/share/vice/C64/kernal.sx64
	cd ${WRKDIR} && ${INSTALL_DATA} 64gs.vrs 4064.vrs sx64.vrs \
		${PREFIX}/share/vice/C64/

.include "../../mk/bsd.pkg.mk"

# this is the emulator's recommended setting
CFLAGS:=		-O5 -finline-functions
