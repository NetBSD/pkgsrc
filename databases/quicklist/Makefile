# $NetBSD: Makefile,v 1.8 2002/10/21 14:48:52 wiz Exp $
#

DISTNAME=	quicklist-0.8.6
CATEGORIES=	databases x11
MASTER_SITES=	ftp://ftp.quicklist.org/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.quicklist.org/
COMMENT=	Simple database like AppleWorks & MS Works

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
USE_X11BASE=	yes

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
