# $NetBSD: Makefile,v 1.11 2003/11/23 07:16:39 salo Exp $
#

DISTNAME=	xbeeb-0.3.6
WRKSRC=		${WRKDIR}/xbeeb
CATEGORIES=	emulators x11
MASTER_SITES=	ftp://ftp.netcom.net.uk/pub/Micros/BBC/Emulators/Xbeeb/
EXTRACT_SUFX=	.tgz

MAINTAINER=	skrll@NetBSD.org
HOMEPAGE=	http://www.netcomuk.co.uk/~james/BBCMicro/Xbeeb/index.html
COMMENT=	Acorn BBC Micro emulator with an X based interface

USE_IMAKE=	yes
MAN_PAGE=	${WRKDIR}/xbeeb.1

XBEEBROOT=	share/xbeeb
MESSAGE_SUBST+=	XBEEBROOT=${XBEEBROOT}
PLIST_SUBST+=	XBEEBROOT=${XBEEBROOT}

# xbeeb build starts in the source directory
do-configure:
	cd ${WRKSRC}/src && ${XMKMF}

post-patch:
	(cd ${WRKSRC}/src && \
	${MV} Config.h Config.h.dist && \
	${SED} 's+^\(#define[	 ]*XBEEBROOT[	 ]*\)[^	 ].*$$+\1"${PREFIX}/${XBEEBROOT}/"+' Config.h.dist > Config.h)
	${SED} -e 's+@XBEEBROOT@+${XBEEBROOT}+g' \
		-e 's+@PREFIX@+${PREFIX}+g' \
		${FILESDIR}/xbeeb.1 > ${MAN_PAGE}

do-build:
	(cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} xbeeb)
	(cd ${WRKSRC}/fonts && \
	for i in *.bdf ; \
	do \
		bdftopcf $$i -o `${BASENAME} $$i .bdf`.pcf ; \
	done)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xbeeb ${PREFIX}/bin/xbeeb
	${INSTALL_MAN} ${MAN_PAGE} ${PREFIX}/man/man1/xbeeb.1
	${INSTALL_DATA_DIR} ${PREFIX}/${XBEEBROOT}
	${INSTALL_DATA_DIR} ${PREFIX}/${XBEEBROOT}/roms
	${INSTALL_DATA_DIR} ${PREFIX}/${XBEEBROOT}/docs
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fonts/xbeeb
	${INSTALL_DATA} ${WRKSRC}/roms/xdfs0.70.rom ${PREFIX}/${XBEEBROOT}/roms/xdfs0.70.rom
	for docfile in ${WRKSRC}/doc/*; do \
		${INSTALL_DATA} $$docfile ${PREFIX}/${XBEEBROOT}/docs; \
	done
	${CP} ${WRKSRC}/fonts/*.pcf ${PREFIX}/lib/X11/fonts/xbeeb
	mkfontdir ${PREFIX}/lib/X11/fonts/xbeeb

.include "../../mk/bsd.pkg.mk"
