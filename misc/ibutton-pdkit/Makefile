# $NetBSD: Makefile,v 1.6 2003/12/30 17:27:31 cjep Exp $
#

DISTNAME=	ulinuxgnu
PKGNAME=	ibutton-pdkit-2.00
WRKSRC=		${WRKDIR}
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.dalsemi.com/pub/auto_id/public/
EXTRACT_SUFX=	.zip

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://ibutton.com/
COMMENT=	1-Wire Public Domain Kit Version 2.00

MAKEFILE=	makefile

SCRIPTS_ENV+=   SED=${SED}

post-patch:
	cd ${WRKSRC};							\
		${MAKE} clean;						\
		for f in *.c; do					\
			${SED} -e 's|/dev/cua0|/dev/tty00|'		\
				-e 's|Linux DS2480|${OPSYS} DS2480|'	\
				$$f > $$f.new;				\
			${MV} -f $$f.new $$f;				\
		done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/atod ${PREFIX}/bin/atod
	${INSTALL_PROGRAM} ${WRKSRC}/count ${PREFIX}/bin/count
	${INSTALL_PROGRAM} ${WRKSRC}/coupler ${PREFIX}/bin/coupler
	${INSTALL_PROGRAM} ${WRKSRC}/debit ${PREFIX}/bin/debit
	${INSTALL_PROGRAM} ${WRKSRC}/initcopr ${PREFIX}/bin/initcopr
	${INSTALL_PROGRAM} ${WRKSRC}/initrov ${PREFIX}/bin/initrov
	${INSTALL_PROGRAM} ${WRKSRC}/list2tag ${PREFIX}/bin/list2tag
	${INSTALL_PROGRAM} ${WRKSRC}/mktag ${PREFIX}/bin/mktag
	${INSTALL_PROGRAM} ${WRKSRC}/mweather ${PREFIX}/bin/mweather
	${INSTALL_PROGRAM} ${WRKSRC}/owsensor ${PREFIX}/bin/owsensor
	${INSTALL_PROGRAM} ${WRKSRC}/swtloop ${PREFIX}/bin/swtloop
	${INSTALL_PROGRAM} ${WRKSRC}/swtoper ${PREFIX}/bin/swtoper
	${INSTALL_PROGRAM} ${WRKSRC}/swtsngl ${PREFIX}/bin/swtsngl
	${INSTALL_PROGRAM} ${WRKSRC}/temp ${PREFIX}/bin/temp
	${INSTALL_PROGRAM} ${WRKSRC}/thermodl ${PREFIX}/bin/thermodl
	${INSTALL_PROGRAM} ${WRKSRC}/thermoms ${PREFIX}/bin/thermoms
	${INSTALL_PROGRAM} ${WRKSRC}/tstfind ${PREFIX}/bin/tstfind
	${INSTALL_PROGRAM} ${WRKSRC}/tstow ${PREFIX}/bin/tstow
	${INSTALL_PROGRAM} ${WRKSRC}/tstowe ${PREFIX}/bin/tstowe

.include "../../mk/bsd.pkg.mk"
