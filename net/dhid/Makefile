# $NetBSD: Makefile,v 1.8 2002/09/23 07:07:02 grant Exp $
#

DISTNAME=	dhid-4.0.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=	hubertf
HOMEPAGE=	http://www.dhis.org/
COMMENT=	Dynamic Host Information System client daemon

DEPENDS+=	gmp-[0-9]*:../../devel/gmp

RCD_SCRIPTS=	dhid

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhid ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/genkeys ${PREFIX}/sbin/dhid-genkeys
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dhid

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
