# $NetBSD: Makefile,v 1.4 2001/08/27 14:35:07 tron Exp $

DISTNAME=	kmysqladmin-0.5.1
CATEGORIES=	databases kde
MASTER_SITES=	http://www.webeifer.de/alwin/programs/download/kmysqladmin/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=       http://www.webeifer.de/alwin/programs/kmysqladmin/
COMMENT=	Mysql administrators GUI

BUILD_DEPENDS+=	automake>=1.4:../../devel/automake
BUILD_DEPENDS+=	autoconf>=2.13:../../devel/autoconf
DEPENDS+=       kdebase>=2.1:../../x11/kdebase2
DEPENDS+=       kdelibs>=2.1:../../x11/kdelibs2
DEPENDS+=       qt2-libs>=2.3.0:../../x11/qt2-libs
DEPENDS+=       mysql-client>=2.22:../../databases/mysql-client

.include "../../x11/kde2/Makefile.part2"

CONFIGURE_ARGS+= --with-mysql-includes=${LOCALBASE}/include/mysql \
		 --with-mysql-libs=${LOCALBASE}/lib/mysql

.include "../../mk/bsd.pkg.mk"

