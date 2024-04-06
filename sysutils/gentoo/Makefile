# $NetBSD: Makefile,v 1.46 2024/04/06 08:06:41 wiz Exp $

DISTNAME=	gentoo-0.20.7
PKGREVISION=	11
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gentoo/}

MAINTAINER=	dunse@goa.nu
HOMEPAGE=	https://sourceforge.net/projects/gentoo/
COMMENT=	Two-pane filemanager using GTK, 100% GUI configurable
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-gtktest

EGDIR=		${PREFIX}/share/examples/gentoo
CONF_FILES+=	${EGDIR}/gentoorc ${PKG_SYSCONFDIR}/gentoorc
CONF_FILES+=	${EGDIR}/gentoogtkrc ${PKG_SYSCONFDIR}/gentoogtkrc

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
