# $NetBSD: Makefile,v 1.2 2004/01/05 16:53:04 cube Exp $
#

DISTNAME=	ghostscript-viewer-0.6
PKGNAME=	sylpheed-claws-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail news x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sylpheed-claws/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://reboot.animeirc.de/sylpheed/ghostscript_viewer/
COMMENT=	Plugin to make Sylpheed-claws display PostScript and PDF attachments

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PLIST_SRC=	${.CURDIR}/../../mail/sylpheed-claws/PLIST.plugins
PLIST_SUBST+=	PLUGIN_NAME=ghostscript_viewer

.include "../../mail/sylpheed-claws/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/ghostscript.mk"

.include "../../mk/bsd.pkg.mk"
