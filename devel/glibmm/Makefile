# $NetBSD: Makefile,v 1.58 2013/12/11 13:41:38 adam Exp $

DISTNAME=	glibmm-2.38.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glibmm/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ bindings for glib
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config perl:run
GNU_CONFIGURE=		yes
EXTRACT_USING=		bsdtar # added for pkg/42258

PKGCONFIG_OVERRIDE+=	gio/giomm.pc.in
PKGCONFIG_OVERRIDE+=	glib/glibmm.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.30.0
BUILDLINK_API_DEPENDS.libsigcpp+=	libsigc++>=2.2.10

# x11/gtkmm needs these tools
INSTALLATION_DIRS=	share/glibmm-2.4/doctool

post-install:
.for tool in doc-install.pl doc-postprocess.pl
	${INSTALL_SCRIPT} ${WRKSRC}/docs/${tool} \
		${DESTDIR}${PREFIX}/share/glibmm-2.4/doctool/${tool}
.endfor

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
