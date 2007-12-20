# $NetBSD: Makefile,v 1.14 2007/12/20 13:17:25 obache Exp $
#

DISTNAME=	ulinuxgnu
PKGNAME=	ibutton-pdkit-2.00
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.dalsemi.com/pub/auto_id/public/
EXTRACT_SUFX=	.zip

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://www.maxim-ic.com/products/ibutton/
COMMENT=	1-Wire Public Domain Kit Version 2.00

MAKE_FILE=	makefile
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin

# Need clean, contains Linux binaries.
BUILD_TARGET=		clean all

SUBST_CLASSES+=		dev
SUBST_STAGE.dev=	pre-configure
SUBST_FILES.dev=	*.c
SUBST_SED.dev=		-e 's|/dev/cua0|${DEFAULT_SERIAL_DEVICE}|'

PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/atod ${DESTDIR}${PREFIX}/bin/atod
	${INSTALL_PROGRAM} ${WRKSRC}/count ${DESTDIR}${PREFIX}/bin/count
	${INSTALL_PROGRAM} ${WRKSRC}/coupler ${DESTDIR}${PREFIX}/bin/coupler
	${INSTALL_PROGRAM} ${WRKSRC}/debit ${DESTDIR}${PREFIX}/bin/debit
	${INSTALL_PROGRAM} ${WRKSRC}/initcopr ${DESTDIR}${PREFIX}/bin/initcopr
	${INSTALL_PROGRAM} ${WRKSRC}/initrov ${DESTDIR}${PREFIX}/bin/initrov
	${INSTALL_PROGRAM} ${WRKSRC}/list2tag ${DESTDIR}${PREFIX}/bin/list2tag
	${INSTALL_PROGRAM} ${WRKSRC}/mktag ${DESTDIR}${PREFIX}/bin/mktag
	${INSTALL_PROGRAM} ${WRKSRC}/mweather ${DESTDIR}${PREFIX}/bin/mweather
	${INSTALL_PROGRAM} ${WRKSRC}/owsensor ${DESTDIR}${PREFIX}/bin/owsensor
	${INSTALL_PROGRAM} ${WRKSRC}/swtloop ${DESTDIR}${PREFIX}/bin/swtloop
	${INSTALL_PROGRAM} ${WRKSRC}/swtoper ${DESTDIR}${PREFIX}/bin/swtoper
	${INSTALL_PROGRAM} ${WRKSRC}/swtsngl ${DESTDIR}${PREFIX}/bin/swtsngl
	${INSTALL_PROGRAM} ${WRKSRC}/temp ${DESTDIR}${PREFIX}/bin/temp
	${INSTALL_PROGRAM} ${WRKSRC}/thermodl ${DESTDIR}${PREFIX}/bin/thermodl
	${INSTALL_PROGRAM} ${WRKSRC}/thermoms ${DESTDIR}${PREFIX}/bin/thermoms
	${INSTALL_PROGRAM} ${WRKSRC}/tstfind ${DESTDIR}${PREFIX}/bin/tstfind
	${INSTALL_PROGRAM} ${WRKSRC}/tstow ${DESTDIR}${PREFIX}/bin/tstow
	${INSTALL_PROGRAM} ${WRKSRC}/tstowe ${DESTDIR}${PREFIX}/bin/tstowe

.include "../../mk/bsd.pkg.mk"
