# $NetBSD: Makefile,v 1.26 2020/01/26 17:31:49 rillig Exp $
#

DISTNAME=	dhid-5.5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dhis.org/
COMMENT=	Dynamic Host Information System client daemon
LICENSE=	2-clause-bsd

RCD_SCRIPTS=	dhid

LDFLAGS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS=	sbin share/doc/dhid

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhid ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/genkeys ${DESTDIR}${PREFIX}/sbin/dhid-genkeys
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DESTDIR}${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DESTDIR}${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${DESTDIR}${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dhid

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
