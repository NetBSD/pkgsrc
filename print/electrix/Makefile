# $NetBSD: Makefile,v 1.88 2022/06/30 11:18:45 nia Exp $

DISTNAME=	electrix-0.2.0
PKGREVISION=	83
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
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
