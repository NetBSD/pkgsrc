# $NetBSD: Makefile,v 1.15 1998/08/20 15:17:11 tsarna Exp $
# FreeBSD Id: Makefile,v 1.4 1997/09/11 03:54:43 fenner Exp 
#

DISTNAME=	vat-4.0b2
CATEGORIES=	mbone
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vat/alpha-test/
DISTFILES=	vatsrc-4.0b2.tar.gz

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www-nrg.ee.lbl.gov/vat/

# If configure is changed to look for libgsm.a in ${PREFIX}/lib, then
# we can use this first BUILD_DEPENDS and save some work.
#BUILD_DEPENDS=	${GSM_WORK}/inc/private.h:${GSM_DIR}:patch
BUILD_DEPENDS=	${GSM_WORK}/lib/libgsm.a:${GSM_DIR}:build
DEPENDS+=	tk-8.0p2:../../x11/tk80
#DEPENDS+=	gsm-1.0.10:${GSM_DIR}

GSM_DIR=	${PKGSRCDIR}/audio/gsm
GSM_WORK=	${GSM_DIR}/${WRKDIR:T}/gsm-1.0-pl10

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-gsm=${GSM_WORK}
INSTALL_TARGET=	install install-man

post-install:
	@strip ${PREFIX}/bin/vat

.include "../../mk/bsd.pkg.mk"
