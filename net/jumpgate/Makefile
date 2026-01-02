# $NetBSD: Makefile,v 1.7 2026/01/02 09:14:07 wiz Exp $

DISTNAME=	jumpgate-0.7
CATEGORIES=	net
MASTER_SITES=	https://jumpgate.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jumpgate.sourceforge.net/
COMMENT=	TCP connection forwarder with capture and syslog support

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jumpgate ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/jumpgate.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
