# $NetBSD: Makefile,v 1.41 2016/08/03 10:23:20 adam Exp $
#

DISTNAME=	imposter-0.3
PKGREVISION=	25
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=imposter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://imposter.sourceforge.net/
COMMENT=	Standalone OpenOffice presentations viewer using GTK2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

LDFLAGS.DragonFly=	-lm
LDFLAGS.SunOS+=		-lm

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
