# $NetBSD: Makefile,v 1.5 2010/02/11 21:47:04 joerg Exp $
#

DISTNAME=	jumpgate-0.7
CATEGORIES=	net
MASTER_SITES=	http://jumpgate.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	TCP connection forwarder with capture and syslog support

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jumpgate ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/jumpgate.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
