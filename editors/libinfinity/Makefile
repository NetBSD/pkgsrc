# $NetBSD: Makefile,v 1.17 2026/01/27 08:39:21 wiz Exp $

DISTNAME=	libinfinity-0.7.2
PKGREVISION=	15
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=gobby/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gobby/libinfinity/
COMMENT=	Collaborative editing library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	libinfgtk.pc.in
PKGCONFIG_OVERRIDE+=	libinfinity.pc.in
PKGCONFIG_OVERRIDE+=	libinfinoted-plugin-manager.pc.in
PKGCONFIG_OVERRIDE+=	libinftext.pc.in
PKGCONFIG_OVERRIDE+=	libinftextgtk.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gsasl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
