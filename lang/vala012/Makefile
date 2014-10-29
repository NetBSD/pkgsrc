# $NetBSD: Makefile,v 1.1 2014/10/29 09:18:50 prlw1 Exp $
#

DISTNAME=	vala-0.12.1
PKGNAME=	${DISTNAME:S/vala/vala012/}
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vala/0.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Vala
COMMENT=	Compiler for the GObject type system (0.12 branch)
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --enable-vapigen
CONFIGURE_ARGS+= --disable-unversioned
USE_LIBTOOL=	yes
USE_TOOLS+=		bison flex gmake pkg-config

PKGCONFIG_OVERRIDE+=	libvala.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
