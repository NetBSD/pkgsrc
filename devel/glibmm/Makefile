# $NetBSD: Makefile,v 1.85 2020/03/30 12:50:45 ryoon Exp $

DISTNAME=	glibmm-2.64.2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glibmm/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.gtkmm.org/
COMMENT=	C++ bindings for glib
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

# With 4.8, one gets the following:
#   error: no matching function for call to 'regex_replace(const char*&, std::regex, const char [3])'
GCC_REQD+=		4.9
USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config perl:run
GNU_CONFIGURE=		yes
EXTRACT_USING=		bsdtar # added for pkg/42258

PKGCONFIG_OVERRIDE+=	gio/giomm.pc.in
PKGCONFIG_OVERRIDE+=	glib/glibmm.pc.in

# x11/gtkmm needs these tools
INSTALLATION_DIRS=	share/glibmm-2.4/doctool

post-install:
.for tool in doc-install.pl doc-postprocess.pl
	${INSTALL_SCRIPT} ${WRKSRC}/docs/${tool} \
		${DESTDIR}${PREFIX}/share/glibmm-2.4/doctool/${tool}
.endfor

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	notmac

.if ${OPSYS} != "Darwin"
PLIST.notmac=	yes
.endif

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.62.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsigcpp+=	libsigc++>=2.9.1
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
