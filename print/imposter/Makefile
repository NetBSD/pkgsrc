# $NetBSD: Makefile,v 1.11 2006/01/24 07:32:31 wiz Exp $
#

DISTNAME=	imposter-0.3
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=imposter/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://imposter.sourceforge.net/
COMMENT=	Standalone OpenOffice presentations viewer using GTK2

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
