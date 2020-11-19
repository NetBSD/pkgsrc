# $NetBSD: Makefile,v 1.38 2020/11/19 09:35:41 schmonz Exp $
#

DISTNAME=		qmail-conf-0.60
PKGREVISION=		5
CATEGORIES=		mail
MASTER_SITES=		http://woodsheep.jp/qmail-conf/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} djbdns-1.05${EXTRACT_SUFX}
SITES.djbdns-1.05.tar.gz= http://cr.yp.to/djbdns/ ftp://cr.yp.to/djbdns/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://woodsheep.jp/qmail-conf.html
COMMENT=		Collection of tools for setting up qmail services

DEPENDS+=		daemontools>=0.70:../../sysutils/daemontools
DEPENDS+=		qmail>=1.03nb7:../../mail/qmail

DJB_CONFIG_CMDS=	${ECHO} ${PREFIX:Q} > ${WRKSRC}/conf-ucspi-tcp;

SUBST_CLASSES+=		djberrno
SUBST_FILES.djberrno=	../djbdns-1.05/error.h

.include "options.mk"

pre-build:
	cd ${WRKSRC} && ${MAKE} -f Makefile.ini djbdns="../djbdns-1.05"

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
