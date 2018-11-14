# $NetBSD: Makefile,v 1.4 2018/11/14 22:21:33 kleink Exp $

DISTNAME=	memphis-0.2.3
PKGNAME=	libmemphis02-0.2.3
PKGREVISION=	3
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=jiuka/}
GITHUB_PROJECT=	memphis
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jiuka/memphis
COMMENT=	Library for OpenStreetMap
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	aclocal autoconf autoheader automake gmake pkg-config

CONFIGURE_ARGS+=--enable-gtk-doc

PKGCONFIG_OVERRIDE+=memphis.pc.in

pre-configure:
	set -e; cd ${WRKSRC}; \
	libtoolize --copy; aclocal -I m4; \
	gtkdocize --copy; autoheader; \
	automake -a --foreign -i --add-missing; autoconf

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
