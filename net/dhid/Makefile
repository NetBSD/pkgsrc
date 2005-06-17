# $NetBSD: Makefile,v 1.17 2005/06/17 03:50:24 jlam Exp $
#

DISTNAME=	dhid-5.2
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dhis.org/
COMMENT=	Dynamic Host Information System client daemon

USE_PKGINSTALL=	yes
RCD_SCRIPTS=	dhid

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhid ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/genkeys ${PREFIX}/sbin/dhid-genkeys
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dhid

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
