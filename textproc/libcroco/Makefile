# $NetBSD: Makefile,v 1.66 2024/05/29 16:34:36 adam Exp $

DISTNAME=	libcroco-0.6.13
PKGREVISION=	10
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libcroco/0.6/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GNOME/libcroco
COMMENT=	Toolkit to parse and manipulate CSS (Cascading Style Sheets)
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	libcroco-0.6.pc

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
