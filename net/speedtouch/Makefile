# $NetBSD: Makefile,v 1.8 2003/10/09 19:09:28 abs Exp $
#

DISTNAME=	speedtouch-1.2-beta2
CATEGORIES=	net
MASTER_SITES=	http://osdn.dl.sourceforge.net/sourceforge/speedtouch/ \
		http://www.alcatel.com/consumer/dsl/
DISTFILES=	${DISTNAME}.tar.bz2 speedmgmt.tar.gz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.xsproject.org/speedtouch/
COMMENT=	Alcatel SpeedTouch USB ADSL modem driver

DEPENDS+=	userppp>=001107:../../net/userppp

USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes

RCD_SCRIPTS=	adsl

post-install:
	${INSTALL_DATA} ${WRKDIR}/mgmt/mgmt.o ${PREFIX}/libdata/alcaudsl.sys

.include "../../mk/bsd.pkg.mk"
