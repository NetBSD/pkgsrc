# $NetBSD: Makefile,v 1.17 2004/10/03 00:13:18 tv Exp $

DISTNAME=	kmysqladmin-0.5.1
PKGREVISION=	7
CATEGORIES=	databases kde
MASTER_SITES=	http://www.webeifer.de/alwin/programs/download/kmysqladmin/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=       http://www.webeifer.de/alwin/programs/kmysqladmin/
COMMENT=	MySQL administration GUI

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

MYSQLDIR=		${BUILDLINK_PREFIX.mysql-client}
CONFIGURE_ARGS+=	--with-mysql-includes=${MYSQLDIR}/include/mysql
CONFIGURE_ARGS+=	--with-mysql-libs=${MYSQLDIR}/lib/mysql

.include "../../databases/mysql-client/buildlink3.mk"
.include "../../x11/kde2/kde2.mk"
.include "../../x11/kdebase2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
