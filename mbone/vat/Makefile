# $NetBSD: Makefile,v 1.12 1998/05/09 15:24:43 frueauf Exp $
# FreeBSD Id: Makefile,v 1.4 1997/09/11 03:54:43 fenner Exp 
#

DISTNAME=	vat-4.0b2
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vat/alpha-test/
DISTFILES=	vatsrc-4.0b2.tar.gz

MAINTAINER=	mycroft@NetBSD.ORG

# If configure is changed to look for libgsm.a in ${PREFIX}/lib, then
# we can use this first BUILD_DEPENDS and save some work.
#BUILD_DEPENDS=	${GSM_WORK}/inc/private.h:${GSM_DIR}:patch
BUILD_DEPENDS=	${GSM_WORK}/lib/libgsm.a:${GSM_DIR}:build
DEPENDS+=	tk-8.0p2:../../x11/tk80
#DEPENDS+=	gsm-1.0.10:${GSM_DIR}

GSM_DIR=	${PKGSRCDIR}/audio/gsm
GSM_WORK=	${GSM_DIR}/${WRKDIR:T}/gsm-1.0-pl10

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= ${MACHINE_ARCH}--netbsd --with-gsm=${GSM_WORK}
INSTALL_TARGET=	install install-man
MAN1=		vat.1

post-install:
	@strip ${PREFIX}/bin/vat

.include "../../mk/bsd.pkg.mk"
