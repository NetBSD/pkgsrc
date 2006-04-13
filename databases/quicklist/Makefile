# $NetBSD: Makefile,v 1.20 2006/04/13 18:23:30 jlam Exp $
#

DISTNAME=	quicklist-0.8.6
PKGREVISION=	5
CATEGORIES=	databases x11
MASTER_SITES=	ftp://ftp.quicklist.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.quicklist.org/
COMMENT=	Simple database like AppleWorks & MS Works

USE_TOOLS+=	msgfmt
GNU_CONFIGURE=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
