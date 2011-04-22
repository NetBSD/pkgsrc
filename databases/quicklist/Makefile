# $NetBSD: Makefile,v 1.23 2011/04/22 13:43:15 obache Exp $
#

DISTNAME=	quicklist-0.8.6
PKGREVISION=	6
CATEGORIES=	databases x11
MASTER_SITES=	# ftp://ftp.quicklist.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.quicklist.org/
COMMENT=	Simple database like AppleWorks & MS Works

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	msgfmt
GNU_CONFIGURE=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
