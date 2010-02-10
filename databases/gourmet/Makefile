# $NetBSD: Makefile,v 1.16 2010/02/10 19:17:34 joerg Exp $
#

DISTNAME=		gourmet-0.8.5.14
PKGREVISION=		6
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=grecipe-manager/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://grecipe-manager.sourceforge.net/
COMMENT=		Recipe database

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../databases/py-metakit/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
