# $NetBSD: Makefile,v 1.1 2014/02/11 14:13:38 wiz Exp $

DISTNAME=	mysql-connector-c++-1.1.3
CATEGORIES=	databases
MASTER_SITES=	https://dev.mysql.com/get/Downloads/Connector-C++/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.mysql.com/downloads/connector/cpp/
COMMENT=	Standardized mysql database driver for C++ development
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	share/doc/mysql-connector-c++

post-install:
	cd ${DESTDIR}${PREFIX} && \
		mv ANNOUNCEMENT COPYING INSTALL \
		Licenses_for_Third-Party_Components.txt \
		README share/doc/mysql-connector-c++

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
