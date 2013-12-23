# $NetBSD: Makefile,v 1.26 2013/12/23 11:57:05 wiz Exp $

DISTNAME=	tits-1.2.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mctavish.co.uk/tits/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mctavish.co.uk/tits/
COMMENT=	Server which provides telnet(1) access to one or more tty ports
LICENSE=	original-bsd

USE_BSD_MAKEFILE=	yes

RCD_SCRIPTS=	tits

INSTALLATION_DIRS=	${PKGMANDIR}/man8 ${PKGMANDIR}/cat8 sbin \
			share/examples/rc.d

INSTALL_MAKE_FLAGS+=	BINDIR=${PREFIX}/sbin

post-patch:
	${MV} ${WRKSRC}/tits.8 ${WRKSRC}/tits.8.in
	${SED} -e 's|/usr/local/etc|${PKG_SYSCONFDIR}|g'	\
	   -e 's|/usr/local|${PREFIX}|g'			\
	   ${WRKSRC}/tits.8.in > ${WRKSRC}/tits.8

post-install:
	${INSTALL_DATA} ${WRKSRC}/tits.conf ${DESTDIR}${PREFIX}/share/examples/

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
