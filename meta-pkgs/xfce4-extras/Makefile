# $NetBSD: Makefile,v 1.2 2004/01/23 21:50:46 jmmv Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-extras-${XFCE4_VERSION}
DISTFILES=	# empty
PKGREVISION=	1
CATEGORIES=	meta-pkgs
COMMENT=	XFce4 extras

NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:	# empty

# Additional plugins etc.
.include "../../audio/xfce4-xmms-plugin/buildlink2.mk"
.include "../../graphics/xfce4-artwork/buildlink2.mk"
.include "../../time/xfce4-datetime-plugin/buildlink2.mk"
.include "../../sysutils/xfce4-diskperf-plugin/buildlink2.mk"
.include "../../sysutils/xfce4-minicmd-plugin/buildlink2.mk"
.include "../../sysutils/xfce4-netload-plugin/buildlink2.mk"
.include "../../sysutils/xfce4-showdesktop-plugin/buildlink2.mk"
.include "../../sysutils/xfce4-systemload-plugin/buildlink2.mk"
.include "../../x11/xfce4-clipman-plugin/buildlink2.mk"
.include "../../x11/xfce4-notes-plugin/buildlink2.mk"

.include "../../meta-pkgs/xfce4/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
