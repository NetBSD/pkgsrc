# $NetBSD: Makefile,v 1.18 2004/04/25 05:36:12 snj Exp $
#

DISTNAME=       gnofin-0.8.4
PKGREVISION=	4
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnofin/}

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://gnofin.sourceforge.net/
COMMENT=	Personal checking/savings account management program

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
