# $NetBSD: Makefile,v 1.9 2021/06/29 06:43:30 wiz Exp $

DISTNAME=	mysql-connector-c++-8.0.25-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL:=Connector-C++/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.mysql.com/downloads/connector/cpp/
COMMENT=	Standardized MySQL database driver for C++ development
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++

post-install:
	${RM} ${DESTDIR}${PREFIX}/INFO_BIN
	${RM} ${DESTDIR}${PREFIX}/INFO_SRC

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
