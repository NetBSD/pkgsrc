# $NetBSD: Makefile,v 1.14 2004/01/23 21:50:43 jmmv Exp $

DISTNAME=	kmysqladmin-0.5.1
PKGREVISION=	5
CATEGORIES=	databases kde
MASTER_SITES=	http://www.webeifer.de/alwin/programs/download/kmysqladmin/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=       http://www.webeifer.de/alwin/programs/kmysqladmin/
COMMENT=	MySQL administration GUI

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

MYSQLDIR=		${BUILDLINK_PREFIX.mysql-client}
CONFIGURE_ARGS+=	--with-mysql-includes=${MYSQLDIR}/include/mysql
CONFIGURE_ARGS+=	--with-mysql-libs=${MYSQLDIR}/lib/mysql

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
