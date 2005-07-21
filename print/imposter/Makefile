# $NetBSD: Makefile,v 1.8 2005/07/21 16:29:56 wiz Exp $
#

DISTNAME=	imposter-0.2
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=imposter/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://imposter.sourceforge.net/
COMMENT=	Standalone OpenOffice presentations viewer using GTK2

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
