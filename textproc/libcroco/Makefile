# $NetBSD: Makefile,v 1.54 2017/06/26 21:28:45 tnn Exp $

DISTNAME=	libcroco-0.6.8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libcroco/0.6/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GNOME/libcroco
COMMENT=	Toolkit to parse and manipulate CSS (Cascading Style Sheets)
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libcroco-0.6.pc

CONFIGURE_ARGS+=	--enable-seleng=yes
CONFIGURE_ARGS+=	--enable-layeng=yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
