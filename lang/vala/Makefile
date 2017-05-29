# $NetBSD: Makefile,v 1.34 2017/05/29 12:16:56 wiz Exp $

DISTNAME=	vala-0.36.0
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

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.32.0

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
