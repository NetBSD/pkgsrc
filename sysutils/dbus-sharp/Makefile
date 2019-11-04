# $NetBSD: Makefile,v 1.22 2019/11/04 21:28:43 rillig Exp $
#

DISTNAME=	dbus-sharp-0.7.0
PKGREVISION=	17
CATEGORIES=	sysutils
MASTER_SITES=	https://cloud.github.com/downloads/mono/dbus-sharp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mono.github.com/dbus-sharp/
COMMENT=	D-Bus for .NET
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	dbus-sharp-1.0.pc.in

SUBST_CLASSES+=		fix-mcs
SUBST_STAGE.fix-mcs=	pre-configure
SUBST_MESSAGE.fix-mcs=	Fix compiler name
SUBST_FILES.fix-mcs=	configure
SUBST_SED.fix-mcs=	-e 's,gmcs,mcs,'

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
