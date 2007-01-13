# $NetBSD: Makefile,v 1.28 2007/01/13 17:35:40 joerg Exp $

DISTNAME=	kmysqladmin-0.7.0
PKGREVISION=	5
CATEGORIES=	databases kde
MASTER_SITES=	http://www.alwins-world.de/programs/download/kmysqladmin/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=       http://www.alwins-world.de/programs/kmysqladmin/
COMMENT=	MySQL administration GUI

USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

MYSQLDIR=		${BUILDLINK_PREFIX.mysql-client}
CONFIGURE_ARGS+=	--with-mysql-include=${MYSQLDIR}/include/mysql
CONFIGURE_ARGS+=	--with-mysql-lib=${MYSQLDIR}/lib/mysql

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../mk/mysql.buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
