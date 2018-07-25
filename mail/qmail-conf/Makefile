# $NetBSD: Makefile,v 1.31 2018/07/25 16:32:34 schmonz Exp $
#

DISTNAME=		qmail-conf-0.60
PKGREVISION=		4
CATEGORIES=		mail
MASTER_SITES=		http://www.din.or.jp/~ushijima/qmail-conf/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} djbdns-1.05${EXTRACT_SUFX}

MAINTAINER=		schmonz@NetBSD.org
#HOMEPAGE=		http://www.din.or.jp/~ushijima/qmail-conf.html
COMMENT=		Collection of tools for setting up qmail services

DEPENDS+=		checkpassword-[0-9]*:../../sysutils/checkpassword
DEPENDS+=		daemontools>=0.70:../../sysutils/daemontools
DEPENDS+=		qmail>=1.03nb7:../../mail/qmail
DEPENDS+=		ucspi-tcp6-[0-9]*:../../net/ucspi-tcp6

SITES.djbdns-1.05.tar.gz=	http://cr.yp.to/djbdns/ ftp://cr.yp.to/djbdns/

DJB_RESTRICTED=		NO
DJB_CONFIG_CMDS=	${ECHO} ${PREFIX:Q} > ${WRKSRC}/conf-ucspi-tcp

SUBST_FILES.djbware+=	../djbdns-1.05/error.h

pre-build:
	cd ${WRKSRC} && ${MAKE} -f Makefile.ini djbdns="../djbdns-1.05"

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
