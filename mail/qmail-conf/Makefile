# $NetBSD: Makefile,v 1.20 2005/03/13 03:25:44 schmonz Exp $
#

DISTNAME=		qmail-conf-0.60
PKGREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		http://www.din.or.jp/~ushijima/qmail-conf/	\
			http://cr.yp.to/djbdns/				\
			ftp://cr.yp.to/djbdns/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} djbdns-1.05${EXTRACT_SUFX}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.din.or.jp/~ushijima/qmail-conf.html
COMMENT=		Collection of tools for setting up qmail services

DEPENDS+=		checkpassword-[0-9]*:../../sysutils/checkpassword
DEPENDS+=		daemontools>=0.70:../../sysutils/daemontools
DEPENDS+=		qmail>=1.03nb7:../../mail/qmail
DEPENDS+=		ucspi-tcp>=0.86:../../net/ucspi-tcp

USE_BUILDLINK3=		yes

BUILD_TARGET=		it
INSTALL_TARGET= 	setup check

do-configure:
	${ECHO} ${CC:Q} ${CFLAGS:Q} > ${WRKSRC}/conf-cc
	${ECHO} ${CC:Q} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${LOCALBASE} > ${WRKSRC}/conf-ucspi-tcp
	${ECHO} ${QMAILDIR} > ${WRKSRC}/conf-qmail

pre-build:
	cd ${WRKSRC} && ${MAKE} -f Makefile.ini djbdns="../djbdns-1.05"

.include "../../mk/bsd.pkg.mk"
