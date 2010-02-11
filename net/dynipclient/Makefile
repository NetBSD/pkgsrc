# $NetBSD: Makefile,v 1.15 2010/02/11 20:50:59 joerg Exp $
#

DISTNAME=	dynip_3.00
PKGNAME=	dynipclient-3.00
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dynip.com/software/unix/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dynip.com/
COMMENT=	Client for the dynip.com dynamic DNS service


PKG_DESTDIR_SUPPORT=	user-destdir

RCD_SCRIPTS=	dynipclient

EGDIR=		${PREFIX}/share/examples/dynipclient
CONF_FILES=	${EGDIR}/dynip.cfg ${PKG_SYSCONFDIR}/dynip.cfg

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${EGDIR}

do-build:
	cd ${WRKSRC} && ./Configure freebsd ${PREFIX}/bin ${PKG_SYSCONFDIR} \
		${PREFIX}/man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dynipadmin ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/dynipclient ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/dynip.cfg ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
