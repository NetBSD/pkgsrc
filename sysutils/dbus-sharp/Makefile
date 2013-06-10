# $NetBSD: Makefile,v 1.1 2013/06/10 11:59:38 obache Exp $
#

DISTNAME=	dbus-sharp-0.7.0
CATEGORIES=	sysutils
MASTER_SITES=	http://cloud.github.com/downloads/mono/dbus-sharp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mono.github.com/dbus-sharp/
COMMENT=	D-Bus for .NET
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	dbus-sharp-1.0.pc.in

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
