# $NetBSD: Makefile,v 1.2 2001/08/13 10:13:59 zuntum Exp $
#

DISTNAME=	qmail-conf-0.55
CATEGORIES=	mail
MASTER_SITES=	http://www.din.or.jp/~ushijima/qmail-conf/		\
		http://cr.yp.to/djbdns/					\
		ftp://cr.yp.to/djbdns/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} djbdns-1.05${EXTRACT_SUFX}

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.din.or.jp/~ushijima/qmail-conf/
COMMENT=	collection of tools for setting up qmail services

DEPENDS+=	qmail>=1.03:../../mail/qmail

NO_PACKAGE=	YES

ALL_TARGET=	#
INSTALL_TARGET= setup check

post-patch:
	${ECHO} ${LOCALBASE} > ${WRKSRC}/conf-ucspi-tcp

pre-build:
	cd ${WRKSRC} && ${MAKE} -f Makefile.ini djbdns="../djbdns-1.05"

.include "../../mk/bsd.pkg.mk"
