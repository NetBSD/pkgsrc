# $NetBSD: Makefile,v 1.24 2012/10/02 21:25:51 asau Exp $
#

DISTNAME=	quicklist-0.8.6
PKGREVISION=	6
CATEGORIES=	databases x11
MASTER_SITES=	# ftp://ftp.quicklist.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.quicklist.org/
COMMENT=	Simple database like AppleWorks & MS Works

USE_TOOLS+=	msgfmt
GNU_CONFIGURE=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
