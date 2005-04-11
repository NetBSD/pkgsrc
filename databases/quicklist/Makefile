# $NetBSD: Makefile,v 1.16 2005/04/11 21:45:15 tv Exp $
#

DISTNAME=	quicklist-0.8.6
PKGREVISION=	4
CATEGORIES=	databases x11
MASTER_SITES=	ftp://ftp.quicklist.org/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.quicklist.org/
COMMENT=	Simple database like AppleWorks & MS Works

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=	yes
USE_X11=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
