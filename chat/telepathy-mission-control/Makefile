# $NetBSD: Makefile,v 1.49 2020/11/21 09:56:27 nia Exp $

DISTNAME=	telepathy-mission-control-4.67
PKGREVISION=	42
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mission-control/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://telepathy.freedesktop.org/wiki/Components/Mission_Control/
COMMENT=	Telepathy component providing abstractions for "end-user" applications

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PYTHON_VERSIONS_ACCEPTED=	27

PKGCONFIG_OVERRIDE+=	libmcclient.pc.in
PKGCONFIG_OVERRIDE+=	libmissioncontrol.pc.in
PKGCONFIG_OVERRIDE+=	mission-control.pc.in

.include "../../lang/python/pyversion.mk"
CONFIGURE_ENV+=		ac_cv_prog_PYTHON=${PYTHONBIN}

.include "../../chat/libtelepathy/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-keyring+=	gnome-keyring>=2.22
.include "../../lang/python/application.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
