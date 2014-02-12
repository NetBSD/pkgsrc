# $NetBSD: Makefile,v 1.68 2014/02/12 23:17:38 tron Exp $

DISTNAME=	kmysqladmin-0.7.2
PKGREVISION=	30
CATEGORIES=	databases kde
MASTER_SITES=	http://www.alwins-world.de/programs/download/kmysqladmin/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alwins-world.de/programs/kmysqladmin/
COMMENT=	MySQL administration GUI

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

MYSQLDIR=		${BUILDLINK_PREFIX.mysql-client}
CONFIGURE_ARGS+=	--with-mysql-include=${MYSQLDIR}/include/mysql
CONFIGURE_ARGS+=	--with-mysql-lib=${MYSQLDIR}/lib/mysql


.include "../../mk/mysql.buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
