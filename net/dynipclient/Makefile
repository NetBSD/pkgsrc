# $NetBSD: Makefile,v 1.14 2007/01/07 09:14:02 rillig Exp $
#

DISTNAME=	dynip_3.00
PKGNAME=	dynipclient-3.00
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dynip.com/software/unix/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dynip.com/
COMMENT=	Client for the dynip.com dynamic DNS service


RCD_SCRIPTS=	dynipclient

EGDIR=		${PREFIX}/share/examples/dynipclient
CONF_FILES=	${EGDIR}/dynip.cfg ${PKG_SYSCONFDIR}/dynip.cfg

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ./Configure freebsd ${PREFIX}/bin ${PKG_SYSCONFDIR} \
		${PREFIX}/man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dynipadmin ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/dynipclient ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/*.1 ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dynip.cfg ${EGDIR}

.include "../../mk/bsd.pkg.mk"
