# $NetBSD: Makefile,v 1.11 2002/01/28 17:36:53 zuntum Exp $
#

DISTNAME=	qmail-conf-0.60
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.din.or.jp/~ushijima/qmail-conf/		\
		http://cr.yp.to/djbdns/					\
		ftp://cr.yp.to/djbdns/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} djbdns-1.05${EXTRACT_SUFX}

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.din.or.jp/~ushijima/qmail-conf/
COMMENT=	collection of tools for setting up qmail services

DEPENDS+=	qmail>=1.03nb1:../../mail/qmail
DEPENDS+=	checkpassword-[0-9]*:../../sysutils/checkpassword

ALL_TARGET=	#
INSTALL_TARGET= setup check

.include "../../mk/bsd.prefs.mk"

NO_MTREE=	YES
LOCALBASE=	/

post-patch:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${STRIPFLAG} > ${WRKSRC}/conf-ld
	# derive LOCALBASE from ${DIGEST}, because we have deliberately altered LOCALBASE
	# and there's no easy way to guess what the real LOCALBASE is
	${ECHO} ${DIGEST} | sed 's,/bin/digest,,' > ${WRKSRC}/conf-ucspi-tcp
	${ECHO} ${QMAILDIR} > ${WRKSRC}/conf-qmail

pre-build:
	cd ${WRKSRC} && ${MAKE} -f Makefile.ini djbdns="../djbdns-1.05"

.include "../../mk/bsd.pkg.mk"
