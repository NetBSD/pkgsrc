# $NetBSD: Makefile,v 1.25 2011/11/01 06:02:01 sbd Exp $
#

DISTNAME=		galculator-1.3.4
PKGREVISION=		7
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=galculator/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://galculator.sourceforge.net/
COMMENT=		Desktop calculator with scientific / RPN modes

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt pkg-config intltool

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
