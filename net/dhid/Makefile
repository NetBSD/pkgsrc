# $NetBSD: Makefile,v 1.6 2001/01/29 11:34:35 wiz Exp $
#

DISTNAME=	dhid-4.0.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=	hubertf
HOMEPAGE=	http://www.dhis.org/

DEPENDS+=	gmp-[0-9]*:../../devel/gmp

do-configure:
	${SED} \
		-e "s,@PREFIX@,${PREFIX},g" \
		-e "s,@ECHO@,${ECHO},g" \
		< ${FILESDIR}/dhid.sh > ${WRKDIR}/dhid.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhid ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/genkeys ${PREFIX}/sbin/dhid-genkeys
	${INSTALL_SCRIPT} ${WRKDIR}/dhid.sh ${PREFIX}/etc/rc.d/dhid
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dhid

.include "../../mk/bsd.pkg.mk"
