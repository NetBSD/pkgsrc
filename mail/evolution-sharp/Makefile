# $NetBSD: Makefile,v 1.19 2013/01/26 21:38:07 adam Exp $
#

DISTNAME=	evolution-sharp-0.20.0
PKGREVISION=	12
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/evolution-sharp/0.20/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.go-evolution.org/EvolutionSharp
COMMENT=	.NET language binding for various Evolution libraries
LICENSE=	gnu-gpl-v2

BROKEN=		Doesn't work with newer versions of evolution-data-server

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	evolution-sharp.pc.in
USE_TOOLS+=		gmake pkg-config

.include "../../lang/mono/buildlink3.mk"
BUILDLINK_API_DEPENDS.evolution-data-server+=	evolution-data-server>=2.24.0
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
