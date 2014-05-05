# $NetBSD: Makefile,v 1.59 2014/05/05 00:48:20 ryoon Exp $

DISTNAME=		gnome-commander-1.2.8.15
PKGREVISION=		30
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-commander/1.2/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc@blackmouse.biz
HOMEPAGE=		http://www.nongnu.org/gcmd/
COMMENT=	GNOME Commander is a fast and powerful graphical filemanager

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config perl

PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 1.2.8.15

#Problem with heimdal, on which this package depends via another packages.
#Simple solution is delete link to fnmatch.h from work directory of package
#after make configure like this:
pre-build:
	${RM} -f ${WRKDIR}/.buildlink/include/krb5/fnmatch.h

PLIST_SRC+=		${PKGDIR}/PLIST

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
