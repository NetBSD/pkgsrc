# $NetBSD: Makefile,v 1.90 2024/06/28 08:36:17 adam Exp $

DISTNAME=	cutter-1.2.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=clear-code/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/clear-code/cutter
COMMENT=	Unit Testing Framework for C and C++
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool pkg-config xgettext msgmerge msgfmt
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--disable-gtktest
GNU_CONFIGURE=		yes
TEST_TARGET=		check

PKGCONFIG_OVERRIDE+=	cppcutter.pc.in
PKGCONFIG_OVERRIDE+=	cutter.pc.in
PKGCONFIG_OVERRIDE+=	gcutter.pc.in
PKGCONFIG_OVERRIDE+=	gdkcutter-pixbuf.pc.in
PKGCONFIG_OVERRIDE+=	libcutter.pc.in
PKGCONFIG_OVERRIDE+=	soupcutter.pc.in

.include "options.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
