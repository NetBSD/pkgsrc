# $NetBSD: Makefile,v 1.14 2002/01/15 23:55:37 rh Exp $
#

DISTNAME=		oaf-0.6.7
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/oaf/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		new object activation framework for GNOME

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

REPLACE_BUILDLINK_SED=	-e "s|${BUILDLINK_DIR}/|${LOCALBASE}/|g"
REPLACE_BUILDLINK+=	oafConf.sh
REPLACE_BUILDLINK+=	oaf-config

.include "../../textproc/libxml/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../devel/popt/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
