# $NetBSD: Makefile,v 1.101 2022/08/11 05:09:13 gutteridge Exp $

DISTNAME=	gnome-keyring-3.36.0
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
PKGREVISION=	2
CATEGORIES=	security gnome
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/GnomeKeyring/
COMMENT=	GNOME password and secret manager
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake pkg-config
USE_TOOLS+=		msgfmt msgmerge xgettext

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

XDG_EGDIR=	${PREFIX}/share/examples/xdg/autostart

CONF_FILES+=	${XDG_EGDIR}/gnome-keyring-pkcs11.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/gnome-keyring-pkcs11.desktop

CONF_FILES+=	${XDG_EGDIR}/gnome-keyring-secrets.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/gnome-keyring-secrets.desktop

CONF_FILES+=	${XDG_EGDIR}/gnome-keyring-ssh.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/gnome-keyring-ssh.desktop

.include "../../devel/glib2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/gcr/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
