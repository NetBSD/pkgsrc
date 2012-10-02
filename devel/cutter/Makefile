# $NetBSD: Makefile,v 1.20 2012/10/02 17:10:45 tron Exp $
#

DISTNAME=	cutter-1.2.1
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cutter/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://cutter.sourceforge.net/
COMMENT=	Unit Testing Framework for C and C++
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config xgettext msgmerge msgfmt
USE_LANGUAGES=	c c++
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	cppcutter.pc.in
PKGCONFIG_OVERRIDE+=	cutter.pc.in
PKGCONFIG_OVERRIDE+=	gcutter.pc.in
PKGCONFIG_OVERRIDE+=	gdkcutter-pixbuf.pc.in
PKGCONFIG_OVERRIDE+=	libcutter.pc.in
PKGCONFIG_OVERRIDE+=	soupcutter.pc.in

TEST_TARGET=	check

.include "options.mk"

# XXX: PR#lib/39986?
LDFLAGS.NetBSD+=	-lgcc_s

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
