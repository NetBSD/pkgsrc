# $NetBSD: Makefile,v 1.4 2014/11/29 16:41:25 adam Exp $

DISTNAME=	mysql-connector-c++-1.1.5
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL:=Connector-C++/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.mysql.com/downloads/connector/cpp/
COMMENT=	Standardized mysql database driver for C++ development
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++

INSTALLATION_DIRS=	share/doc/mysql-connector-c++

post-install:
	cd ${DESTDIR}${PREFIX} && mv ANNOUNCEMENT COPYING INSTALL README \
		Licenses_for_Third-Party_Components.txt \
		share/doc/mysql-connector-c++/

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
