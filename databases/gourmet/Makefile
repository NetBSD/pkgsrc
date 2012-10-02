# $NetBSD: Makefile,v 1.31 2012/10/02 21:25:17 asau Exp $
#

DISTNAME=		gourmet-0.8.5.14
PKGREVISION=		20
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=grecipe-manager/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://grecipe-manager.sourceforge.net/
COMMENT=		Recipe database

USE_PKGLOCALEDIR=	yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../databases/py-metakit/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
