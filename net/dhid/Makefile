# $NetBSD: Makefile,v 1.3 1999/08/04 14:04:36 jlam Exp $
#

DISTNAME=	dhid-3.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.dhis.org/sp/

ALL_TARGET=	dhid

pre-patch:
	${MV} -f ${WRKSRC}/dtool ${WRKSRC}/dtool.in

do-configure:
	${SED} -e "s,@PREFIX@,${PREFIX},g" ${WRKSRC}/dtool.in >${WRKSRC}/dtool
	${SED} -e "s,@PREFIX@,${PREFIX},g" -e "s,@ECHO@,${ECHO},g" \
		${FILESDIR}/dhid.sh >${WRKDIR}/dhid.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhid ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/dtool ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/dtool.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/dhid.8 ${PREFIX}/man/man8
	${INSTALL_SCRIPT} ${WRKDIR}/dhid.sh ${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/dhid.conf ${PREFIX}/share/examples
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/dhid
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dhid

.include "../../mk/bsd.pkg.mk"
