# $NetBSD: Makefile,v 1.4 2002/09/19 09:04:19 jlam Exp $
#

DISTNAME=	speedtouch-1.1
CATEGORIES=	net
MASTER_SITES=	http://www.xsproject.org/speedtouch/files/ \
		http://www.alcatel.com/consumer/dsl/
DISTFILES=	${DISTNAME}.tar.bz2 speedmgmt.tar.gz

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.xsproject.org/speedtouch/
COMMENT=	Alcatel SpeedTouch USB ADSL modem driver

DEPENDS+=	userppp-001107:../../net/userppp

GNU_CONFIGURE=	yes

RCD_SCRIPTS=	adsl

post-install:
	${INSTALL_DATA} ${WRKDIR}/mgmt/mgmt.o ${PREFIX}/libdata/alcaudsl.sys

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
