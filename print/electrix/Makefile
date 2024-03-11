# $NetBSD: Makefile,v 1.98 2024/03/11 21:15:59 wiz Exp $

DISTNAME=	electrix-0.2.0
PKGREVISION=	93
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=electrix/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://electrix.sourceforge.net/
COMMENT=	Application to view PDF files
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	intltool pkg-config
PYTHON_VERSIONS_ACCEPTED=	27

WAF_HAS_LIBDIR=	no
WAF_HAS_MANDIR=	no

.include "../../devel/waf/waf.mk"
BUILDLINK_API_DEPENDS.poppler+=	poppler>=23.12.0
.include "../../print/poppler/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
