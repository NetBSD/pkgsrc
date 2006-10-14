# $NetBSD: Makefile,v 1.28 2006/10/14 09:24:10 obache Exp $

DISTNAME=	gentoo-0.11.56
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gentoo/}

MAINTAINER=	dunse@goa.nu
HOMEPAGE=	http://www.obsession.se/gentoo/
COMMENT=	Two-pane filemanager using GTK+, 100% GUI configurable

USE_TOOLS+=		msgfmt
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/gentoo
CONF_FILES=	${EGDIR}/gentoorc ${PKG_SYSCONFDIR}/gentoorc
CONF_FILES+=	${EGDIR}/gentoogtkrc ${PKG_SYSCONFDIR}/gentoogtkrc

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
