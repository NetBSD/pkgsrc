# $NetBSD: Makefile,v 1.19 2004/11/08 10:39:14 adam Exp $

DISTNAME=	gentoo-0.11.53
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gentoo/}

MAINTAINER=	dunse@goa.nu
HOMEPAGE=	http://www.obsession.se/gentoo/
COMMENT=	Two-pane filemanager using GTK+, 100% GUI configurable

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/gentoo
CONF_FILES=	${EGDIR}/gentoorc ${PKG_SYSCONFDIR}/gentoorc
CONF_FILES+=	${EGDIR}/gentoogtkrc ${PKG_SYSCONFDIR}/gentoogtkrc

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
