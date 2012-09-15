# $NetBSD: Makefile,v 1.7 2012/09/15 10:06:22 obache Exp $

DISTNAME=	eggdbus-0.6
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://cgit.freedesktop.org/~david/eggdbus/snapshot/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cgit.freedesktop.org/~david/eggdbus
COMMENT=	GObject bindings for DBus
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf autoheader automake gmake pkg-config
GNU_CONFIGURE=		yes
TEST_TARGET=		check
PKGCONFIG_OVERRIDE+=	eggdbus-1.pc.in

pre-configure:
	set -e; cd ${WRKSRC}; gtkdocize --flavour no-tmpl; \
	libtoolize -c -f; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
