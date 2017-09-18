# $NetBSD: Makefile,v 1.31 2017/09/18 09:52:57 maya Exp $

DISTNAME=	Renaissance-0.9.0
PKGREVISION=	12
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
