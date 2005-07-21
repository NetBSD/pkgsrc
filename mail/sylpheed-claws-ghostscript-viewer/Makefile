# $NetBSD: Makefile,v 1.12 2005/07/21 16:29:52 wiz Exp $
#

DISTNAME=	ghostscript-viewer-0.6
PKGNAME=	sylpheed-claws-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	mail news x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sylpheed-claws/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://reboot.animeirc.de/sylpheed/ghostscript_viewer/
COMMENT=	Plugin to make Sylpheed-claws display PostScript and PDF attachments

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PLIST_SRC=	${.CURDIR}/../../mail/sylpheed-claws/PLIST.plugins
PLIST_SUBST+=	PLUGIN_NAME=ghostscript_viewer
MESSAGE_SRC+=	${.CURDIR}/../../mail/sylpheed-claws/MESSAGE.plugins

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mail/sylpheed-claws/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
