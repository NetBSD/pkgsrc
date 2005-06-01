# $NetBSD: Makefile,v 1.17 2005/06/01 18:02:42 jlam Exp $
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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
