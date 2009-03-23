# $NetBSD: Makefile,v 1.8 2009/03/23 00:51:47 joerg Exp $

DISTNAME=	pgadmin3-1.8.4
CATEGORIES=	databases
MASTER_SITES=	http://www.pgadmin.org/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.pgadmin.org/
COMMENT=	Graphical PostgreSQL client and administration tool

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake msgfmt

CONFIGURE_ARGS+=	--with-wx=${BUILDLINK_PREFIX.wxGTK28}

# CONFIGURE_ARGS+=	--enable-debug
# PLIST_VARS.debug=	yes

PLIST_VARS+=	debug

.include "../../mk/pgsql.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../x11/wxGTK28-contrib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
