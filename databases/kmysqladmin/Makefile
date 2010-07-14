# $NetBSD: Makefile,v 1.43 2010/07/14 11:11:18 sbd Exp $

DISTNAME=	kmysqladmin-0.7.2
PKGREVISION=	6
CATEGORIES=	databases kde
MASTER_SITES=	http://www.alwins-world.de/programs/download/kmysqladmin/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alwins-world.de/programs/kmysqladmin/
COMMENT=	MySQL administration GUI

PKG_DESTDIR_SUPPORT=	user-destdir

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
