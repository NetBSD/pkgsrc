# $NetBSD: Makefile,v 1.5 2004/01/24 15:06:57 grant Exp $
#

DISTNAME=	apotheke-0.2
PKGREVISION=	3
CATEGORIES=	sysutils gnome
MASTER_SITES=	ftp://ftp.berlios.de/pub/apotheke/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://apotheke.berlios.de/
COMMENT=	CVS view for Nautilus

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make

GCONF2_SCHEMAS+=	apotheke.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../sysutils/nautilus/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
