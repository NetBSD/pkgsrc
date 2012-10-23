# $NetBSD: Makefile,v 1.6 2012/10/23 17:18:30 asau Exp $
#

DISTNAME=	jumpgate-0.7
CATEGORIES=	net
MASTER_SITES=	http://jumpgate.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	TCP connection forwarder with capture and syslog support

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jumpgate ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/jumpgate.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
