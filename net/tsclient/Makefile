# $NetBSD: Makefile,v 1.14 2004/02/20 12:13:40 jmmv Exp $
#

DISTNAME=		tsclient-0.132
PKGREVISION=		6
CATEGORIES=		net
MASTER_SITES=		http://www.gnomepro.com/tsclient/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gnomepro.com/tsclient/
COMMENT=		GNOME2 Frontend for rdesktop

DEPENDS+=       	rdesktop-[0-9]*:../../net/rdesktop
DEPENDS+=       	vncviewer-[0-9]*:../../net/vncviewer
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_PERL5=		run
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
