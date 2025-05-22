# $NetBSD: Makefile,v 1.41 2025/05/22 04:51:29 schmonz Exp $

DISTNAME=		qmail-conf-0.60
PKGREVISION=		6
CATEGORIES=		mail
MASTER_SITES=		http://woodsheep.jp/qmail-conf/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} djbdns-1.05${EXTRACT_SUFX}
SITES.djbdns-1.05.tar.gz= http://cr.yp.to/djbdns/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://woodsheep.jp/qmail-conf.html
COMMENT=		Collection of tools for setting up qmail services
LICENSE=		public-domain

DEPENDS+=		daemontools>=0.70:../../sysutils/daemontools
DEPENDS+=		qmail>=1.03nb7:../../mail/qmail
DEPENDS+=		{ucspi-tcp6-[0-9]*,ucspi-tcp-[0-9]*}:../../net/ucspi-tcp6

FORCE_C_STD=		c89

DJB_CONFIG_CMDS=	${ECHO} ${PREFIX:Q} > ${WRKSRC}/conf-ucspi-tcp;
DJB_ERRNO_FIXUP=	../djbdns-1.05/error.h

.include "options.mk"

pre-build:
	cd ${WRKSRC} && ${MAKE} -f Makefile.ini djbdns="../djbdns-1.05"

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
