# $NetBSD: Makefile,v 1.17 2008/07/10 13:27:02 joerg Exp $
#

DISTNAME=	Renaissance-0.8.0
PKGREVISION=	8
CATEGORIES=	devel gnustep
MASTER_SITES=	http://www.gnustep.it/Renaissance/Download/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.it/Renaissance/
COMMENT=	Structured GNUstep user interface development framework

PKG_DESTDIR_SUPPORT=	destdir

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
