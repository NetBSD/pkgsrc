# $NetBSD: Makefile,v 1.9 2003/05/02 11:56:21 wiz Exp $
#

DISTNAME=	gentoo-0.11.34
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gentoo/}

MAINTAINER=	dunse@goa.nu
HOMEPAGE=	http://www.obsession.se/gentoo/
COMMENT=	Two-pane filemanager using GTK+, 100% GUI configurable

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/gentoo
CONF_FILES=	${EGDIR}/gentoorc ${PKG_SYSCONFDIR}/gentoorc
CONF_FILES+=	${EGDIR}/gentoogtkrc ${PKG_SYSCONFDIR}/gentoogtkrc

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
