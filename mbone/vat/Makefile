# $NetBSD: Makefile,v 1.8 1998/04/15 10:38:33 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1997/09/11 03:54:43 fenner Exp 
#

DISTNAME=	vat-4.0b2
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vat/alpha-test/
DISTFILES=	vatsrc-4.0b2.tar.gz

MAINTAINER=	mycroft@NetBSD.ORG

GSM_DIR=	${PORTSDIR}/audio/gsm
GSM_WORK=	${GSM_DIR}/${WRKDIR:T}/gsm-1.0-pl10

# If configure is changed to look for libgsm.a in ${PREFIX}/lib, then
# we can use this first BUILD_DEPENDS and save some work.
#BUILD_DEPENDS=	${GSM_WORK}/inc/private.h:${GSM_DIR}:patch
BUILD_DEPENDS=	${GSM_WORK}/lib/libgsm.a:${GSM_DIR}:build
LIB_DEPENDS=	tk80:${PORTSDIR}/x11/tk80
#LIB_DEPENDS+=	gsm:${GSM_DIR}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= ${MACHINE_ARCH}--netbsd --with-gsm=${GSM_WORK}
INSTALL_TARGET=	install install-man
MAN1=		vat.1

post-install:
	@strip ${PREFIX}/bin/vat

.include "../../mk/bsd.pkg.mk"
