# $NetBSD: Makefile,v 1.14 2003/05/02 11:54:51 wiz Exp $
#

DISTNAME=       gnofin-0.8.4
PKGREVISION=	2
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnofin/}

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://gnofin.sourceforge.net/
COMMENT=	Personal checking/savings account management program

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
