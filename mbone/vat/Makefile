# $NetBSD: Makefile,v 1.27 2000/01/26 22:14:18 jlam Exp $
#

DISTNAME=		vatsrc-4.0b2
PKGNAME=		${DISTNAME:S/src//}
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		mbone
MASTER_SITES=		ftp://ftp.ee.lbl.gov/conferencing/vat/alpha-test/

MAINTAINER=		mycroft@netbsd.org
HOMEPAGE=		http://www-nrg.ee.lbl.gov/vat/

BUILD_DEPENDS+=		${GSM_WORK}/inc/private.h:${GSM_DIR}:patch
BUILD_DEPENDS+=		${LOCALBASE}/bin/autoconf:../../devel/autoconf
DEPENDS+=		tk-8.0.5:../../x11/tk80
DEPENDS+=		gsm-1.0.10:${GSM_DIR}

NOT_FOR_PLATFORM=	*-*-alpha	# filter.cc compiler error

GSM_DIR=		${.CURDIR}/../../audio/gsm
GSM_WORK=		${GSM_DIR}/${WRKDIR:T}/gsm-1.0-pl10

USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=		-I${LOCALBASE}/include -I${GSM_WORK}/inc

INSTALL_TARGET=		install install-man

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf

post-install:
	@strip ${PREFIX}/bin/vat

pre-clean:
	@cd ${GSM_DIR}; ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
