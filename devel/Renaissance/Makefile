# $NetBSD: Makefile,v 1.39 2020/11/05 09:06:46 ryoon Exp $

DISTNAME=	Renaissance-0.9.0
PKGREVISION=	20
CATEGORIES=	devel gnustep
MASTER_SITES=	http://www.gnustep.it/Renaissance/Download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnustep.it/Renaissance/
COMMENT=	Structured GNUstep user interface development framework

PKG_DESTDIR_SUPPORT=	destdir

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
MAKE_FILE=	GNUmakefile

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
