# $NetBSD: Makefile,v 1.1.1.1 2006/01/30 06:39:05 xtraeme Exp $
#

DISTNAME=	pcmanfm-0.1.8.9
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcmanfm/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://pcmanfm.sourceforge.net/
COMMENT=	Extremly fast and lightweight file manager

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../sysutils/gamin/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
