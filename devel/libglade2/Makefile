# $NetBSD: Makefile,v 1.8 2003/01/05 12:17:43 jmmv Exp $
#

DISTNAME=		libglade-2.0.1
PKGNAME=		${DISTNAME:S/libglade/libglade2/}
PKGREVISION=		3
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libglade/2.0/}

MAINTAINER=		jmmv@netbsd.org
HOMEPAGE=		http://www.daa.com.au/~james/gnome/
COMMENT=		Runtime interpreter for GLADE gui files (v2)

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ENV+=		jh_cv_path_python="${PYTHONBIN}"
CONFIGURE_ARGS+=	--enable-gtk-doc=no

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/libglade/2.0

.include "../../lang/python/application.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
