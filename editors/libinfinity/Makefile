# $NetBSD: Makefile,v 1.3 2024/05/29 16:32:23 adam Exp $

DISTNAME=	libinfinity-0.7.2
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=gobby/}

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
