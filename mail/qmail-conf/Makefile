# $NetBSD: Makefile,v 1.27 2010/03/15 17:30:28 schmonz Exp $
#

DISTNAME=		qmail-conf-0.60
PKGREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		http://www.din.or.jp/~ushijima/qmail-conf/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} djbdns-1.05${EXTRACT_SUFX}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.din.or.jp/~ushijima/qmail-conf.html
COMMENT=		Collection of tools for setting up qmail services

DEPENDS+=		checkpassword-[0-9]*:../../sysutils/checkpassword
DEPENDS+=		daemontools>=0.70:../../sysutils/daemontools
DEPENDS+=		qmail>=1.03nb7:../../mail/qmail
DEPENDS+=		ucspi-tcp>=0.86:../../net/ucspi-tcp

SITES.djbdns-1.05.tar.gz=	http://cr.yp.to/djbdns/ ftp://cr.yp.to/djbdns/

PKG_DESTDIR_SUPPORT=	user-destdir

DJB_RESTRICTED=		NO
DJB_CONFIG_CMDS=	${ECHO} ${LOCALBASE:Q} > ${WRKSRC}/conf-ucspi-tcp

SUBST_FILES.djbware+=	../djbdns-1.05/error.h

pre-build:
	cd ${WRKSRC} && ${MAKE} -f Makefile.ini djbdns="../djbdns-1.05"

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
