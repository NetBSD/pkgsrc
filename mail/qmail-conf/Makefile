# $NetBSD: Makefile,v 1.21 2005/03/23 00:51:09 schmonz Exp $
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

DJB_RESTRICTED=		NO
DJB_CONFIG_CMDS=	${ECHO} ${LOCALBASE} > ${WRKSRC}/conf-ucspi-tcp

pre-build:
	cd ${WRKSRC} && ${MAKE} -f Makefile.ini djbdns="../djbdns-1.05"

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
