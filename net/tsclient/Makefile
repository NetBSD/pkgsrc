# $NetBSD: Makefile,v 1.23 2005/07/16 01:19:17 jlam Exp $
#

DISTNAME=		tsclient-0.132
PKGREVISION=		9
CATEGORIES=		net
MASTER_SITES=		http://www.gnomepro.com/tsclient/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnomepro.com/tsclient/
COMMENT=		GNOME2 Frontend for rdesktop

DEPENDS+=       	rdesktop-[0-9]*:../../net/rdesktop
DEPENDS+=       	vncviewer-[0-9]*:../../net/vncviewer
BUILD_USES_MSGFMT=	yes

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake perl:run
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
