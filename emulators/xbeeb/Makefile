# $NetBSD: Makefile,v 1.5 2001/01/29 11:34:26 wiz Exp $
#

DISTNAME=	xbeeb-0.3.6
CATEGORIES=	emulators x11
MASTER_SITES=	ftp://ftp.netcom.net.uk/pub/Micros/BBC/Emulators/Xbeeb/
EXTRACT_SUFX=	.tgz

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://www.netcomuk.co.uk/~james/BBCMicro/Xbeeb/index.html

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/xbeeb
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
testt:
	${SED} -e 's+@XBEEBROOT@+${XBEEBROOT}+g' \
		-e 's+@PREFIX@+${PREFIX}+g' \
		${FILESDIR}/xbeeb.1 > ${MAN_PAGE}

do-build:
	(cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} xbeeb)
	(cd ${WRKSRC}/fonts && \
	for i in *.bdf ; \
	do \
		bdftopcf $$i -o `basename $$i .bdf`.pcf ; \
	done)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xbeeb ${PREFIX}/bin/xbeeb
	${INSTALL_MAN} ${MAN_PAGE} ${PREFIX}/man/man1/xbeeb.1
	${MKDIR} ${PREFIX}/${XBEEBROOT}
	${MKDIR} ${PREFIX}/${XBEEBROOT}/roms
	${MKDIR} ${PREFIX}/${XBEEBROOT}/docs
	${MKDIR} ${PREFIX}/lib/X11/fonts/xbeeb
	${INSTALL_DATA} ${WRKSRC}/roms/xdfs0.70.rom ${PREFIX}/${XBEEBROOT}/roms/xdfs0.70.rom
	for docfile in ${WRKSRC}/doc/*; do \
		${INSTALL_DATA} $$docfile ${PREFIX}/${XBEEBROOT}/docs; \
	done
	${CP} ${WRKSRC}/fonts/*.pcf ${PREFIX}/lib/X11/fonts/xbeeb
	mkfontdir ${PREFIX}/lib/X11/fonts/xbeeb

.include "../../mk/bsd.pkg.mk"
