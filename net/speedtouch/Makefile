# $NetBSD: Makefile,v 1.2 2001/08/06 21:32:39 wiz Exp $
#

DISTNAME=	speedtouch-21062001
CATEGORIES=	net
MASTER_SITES=	http://www.xsproject.org/speedtouch/files/ \
		http://www.alcatel.com/consumer/dsl/
DISTFILES=	${DISTNAME}.tar.gz speedmgmt.tar.gz

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.xsproject.org/speedtouch/
COMMENT=	Alcatel SpeedTouch USB ADSL modem driver

DEPENDS+=	userppp-001107:../../net/userppp

MAKE_ENV+=	PREFIX=${PREFIX} INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"

post-build:
	${SED} "s:@PREFIX@:${PREFIX}:g" ${FILESDIR}/adsl.sh > ${WRKDIR}/adsl.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/adsl.sh ${PREFIX}/etc/rc.d/adsl
	${INSTALL_DATA} ${WRKDIR}/mgmt/mgmt.o ${PREFIX}/libdata/alcaudsl.sys
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/speedtouch
	${INSTALL_DATA} ${WRKSRC}/INSTALL-BSD ${PREFIX}/share/doc/speedtouch/INSTALL-BSD
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/doc/speedtouch/README

.include "../../mk/bsd.pkg.mk"
