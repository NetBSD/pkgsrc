# $NetBSD: Makefile,v 1.1.1.1 2000/05/22 22:13:11 skrll Exp $
#

DISTNAME=	xbeeb-0.3.6
CATEGORIES=	emulators x11
MASTER_SITES=	ftp://ftp.netcom.net.uk/pub/Micros/BBC/Emulators/Xbeeb/

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://www.netcomuk.co.uk/~james/BBCMicro/Xbeeb/index.html

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/xbeeb
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

XBEEBROOT=	share/xbeeb

# xbeeb build starts in the source directory
do-configure:
	cd ${WRKSRC}/src && ${XMKMF}

post-patch:
	(cd ${WRKSRC}/src && \
	${MV} Config.h Config.h.dist && \
	${SED} 's+^\(#define[	 ]*XBEEBROOT[	 ]*\)[^	 ].*$$+\1"${PREFIX}/${XBEEBROOT}/"+' Config.h.dist > Config.h)
	${SED} 's+#XBEEBROOT#+${XBEEBROOT}+g' ${PKGDIR}/PLIST > ${PLIST_SRC}

do-build:
	(cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} xbeeb)
	(cd ${WRKSRC}/fonts && \
	for i in *.bdf ; \
	do \
		bdftopcf $$i -o `basename $$i .bdf`.pcf ; \
	done)
	${ECHO} > ${MESSAGE_FILE} "You must copy the BBC \"BASIC2\" ROM image to"
	${ECHO} >> ${MESSAGE_FILE} "\"${PREFIX}/${XBEEBROOT}/roms/BASIC2.rom\""
	${ECHO} >> ${MESSAGE_FILE} "and the BBC \"OS1.2\" ROM image to"
	${ECHO} >> ${MESSAGE_FILE} "\"${PREFIX}/${XBEEBROOT}/roms/OS1.2.rom\"."

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xbeeb ${PREFIX}/bin/xbeeb
	${MKDIR} ${PREFIX}/${XBEEBROOT}
	${MKDIR} ${PREFIX}/${XBEEBROOT}/roms
	${MKDIR} ${PREFIX}/${XBEEBROOT}/docs
	${INSTALL_DATA} ${WRKSRC}/roms/xdfs0.70.rom ${PREFIX}/${XBEEBROOT}/roms/xdfs0.70.rom
	for docfile in ${WRKSRC}/doc/*; do \
		${INSTALL_DATA} $$docfile ${PREFIX}/${XBEEBROOT}/docs; \
	done
	${MKDIR} ${PREFIX}/lib/X11/fonts/xbeeb
	${CP} ${WRKSRC}/fonts/*.pcf ${PREFIX}/lib/X11/fonts/xbeeb
	${TOUCH} ${PREFIX}/lib/X11/fonts/xbeeb/fonts.alias
	mkfontdir ${PREFIX}/lib/X11/fonts/xbeeb

.include "../../mk/bsd.pkg.mk"
