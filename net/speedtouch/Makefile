# $NetBSD: Makefile,v 1.5 2003/01/28 22:03:56 jlam Exp $
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

USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes

RCD_SCRIPTS=	adsl

post-install:
	${INSTALL_DATA} ${WRKDIR}/mgmt/mgmt.o ${PREFIX}/libdata/alcaudsl.sys

.include "../../mk/bsd.pkg.mk"
