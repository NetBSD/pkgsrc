# $NetBSD: Makefile,v 1.24 2011/01/13 13:38:26 wiz Exp $
#

DISTNAME=	ami-1.0.11
PKGREVISION=	12
CATEGORIES=	korean inputmethod
MASTER_SITES=	http://kldp.net/frs/download.php/942/
# http://kldp.net/frs/download.php/942/ami-1.2.3.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kldp.net/projects/ami
COMMENT=	Korean input method

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
