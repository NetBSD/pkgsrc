# $NetBSD: Makefile,v 1.8 2004/04/25 08:33:08 snj Exp $
#

DISTNAME=	dynip_3.00
PKGNAME=	dynipclient-3.00
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dynip.com/software/unix/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dynip.com/
COMMENT=	Client for the dynip.com dynamic DNS service

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES

RCD_SCRIPTS=	dynipclient

EGDIR=		${PREFIX}/share/examples/dynipclient
CONF_FILES=	${EGDIR}/dynip.cfg ${PKG_SYSCONFDIR}/dynip.cfg

do-build:
	cd ${WRKSRC} && ./Configure freebsd ${PREFIX}/bin ${PKG_SYSCONFDIR} \
		${PREFIX}/man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dynipadmin ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/dynipclient ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/*.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dynip.cfg ${EGDIR}

.include "../../mk/bsd.pkg.mk"
