# $NetBSD: Makefile,v 1.32 2016/02/04 12:16:42 wiz Exp $

DISTNAME=	vala-0.30.0
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vala/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Vala
COMMENT=	Compiler for the GObject type system
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		bison flex gmake pkg-config

PKGCONFIG_OVERRIDE+=	libvala.pc.in
PKGCONFIG_OVERRIDE+=	vapigen/vapigen.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.24.0

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
